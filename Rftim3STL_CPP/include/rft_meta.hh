#pragma once
#include "rft_global_cpp.hh"
#include "rft_io.hh"
#include "rft_paths.hh"
#include "rft_postgre_sql.hh"
#include "rft_string.hh"
#include "rft_time.hh"

struct rft_meta_csv
{
    std::string competition_name;
    std::string problem_number;
    std::string problem_title;
    int difficulty;
    std::vector<std::string> algorithms;
};

struct rft_meta_competition
{
    long id;
    std::string competition_name;
    std::string timestamp;
    int rank;
    int rating;
    std::string folder_path;
};

struct rft_meta_problem
{
    long id;
    long competition_id;
    std::string problem_number;
    std::string problem_title;
    std::string problem_description;
    std::string problem_input;
    int difficulty;
    std::string folder_path;
};

struct rft_meta_solution
{
    long id;
    long problem_id;
    std::string solution_name;
    bool test_status;
    double runtime;
    double memory;
    std::vector<std::string> algorithms;
    std::string file_path;
};

static const std::filesystem::path META_PROJECT_PATH = ACTIVE_PROJECT_PATH / "Rftim3Meta";
static const std::filesystem::path META_PROJECT_CMAKE_FILE = ACTIVE_PROJECT_PATH / "CMakeLists.txt";
static const std::filesystem::path META_PROJECT_CMAKE_TEMPLATE_FILE = META_PROJECT_PATH / TEMPLATES_DIRECTORY / "MetaProjectCMakeListsTemplate.txt";
static const std::filesystem::path META_PROJECT_PROBLEMS_DIRECTORY_PATH = META_PROJECT_PATH / PROBLEMS_DIRECTORY;
static const std::filesystem::path META_PROBLEM_NAMES_FILE = META_PROJECT_PATH / TEMPLATES_DIRECTORY / "MetaProblemNames.csv";
static const std::filesystem::path META_PROBLEM_HEADER_TEMPLATE_FILE = META_PROJECT_PATH / TEMPLATES_DIRECTORY / "MetaHeaderTemplate.txt";
static const std::filesystem::path META_PROBLEM_SOURCE_FILE_TEMPLATE_FILE = META_PROJECT_PATH / TEMPLATES_DIRECTORY / "MetaSourceFileTemplate.txt";
static const std::filesystem::path META_PROBLEM_CMAKE_TEMPLATE_FILE = META_PROJECT_PATH / TEMPLATES_DIRECTORY / "MetaCMakeListsTemplate.txt";
static const std::filesystem::path META_PROBLEMS_DIRECTORY_PATH = ACTIVE_PROJECT_PATH.parent_path().parent_path() / "Rftim3Meta" / PROBLEMS_DIRECTORY;

static void printMetaCSV(rft_meta_csv meta_csv)
{
    std::cout << meta_csv.competition_name << "\n";
    std::cout << meta_csv.problem_number << "\n";
    std::cout << meta_csv.problem_title << "\n";
    std::cout << meta_csv.difficulty << "\n";
    for (int i = 0; i < meta_csv.algorithms.size(); i++)
    {
        if (i == meta_csv.algorithms.size() - 1)
            std::cout << meta_csv.algorithms[i] << "\n";
        else
            std::cout << meta_csv.algorithms[i] << ", ";
    }
}

static void printAllMetaCSV(std::vector<rft_meta_csv> meta_csv)
{
    for (auto &&i : meta_csv)
    {
        printMetaCSV(i);
    }
}

static std::vector<std::string> getAllRowsCSVMetaProblemNames()
{
    static std::vector<std::string> v = {};

    // open file read
    in.open(META_PROBLEM_NAMES_FILE);
    if (!in.is_open())
    {
        std::cerr << "Error opening problem names file input: " << META_PROBLEM_NAMES_FILE << std::endl;
        return {};
    }

    // store problem names in memory
    while (!in.eof())
    {
        std::string s = "";
        std::getline(in, s);
        v.push_back(s);
    }

    // close input stream
    if (in.is_open())
        in.close();

    return v;
}

static std::string refactorProblemId(std::string input)
{
    if (input.find("meta_") == std::string::npos)
    {
        std::string res = "";
        res += "meta_";

        int c = 0;

        for (int i = 0; i < input.size(); i++)
        {
            if (isdigit(input[i]))
                c++;
            else
                break;
        }

        c = 8 - c;
        for (int i = 0; i < c; i++)
        {
            res += "0";
        }

        res += input;
        return res;
    }
    else
        return input;
}

static std::string sanitizeProblemName(std::string input)
{
    std::string res = "";

    if (input.size() > 0)
    {
        std::string t = input;
        std::stringstream ss(t);
        std::string s;
        std::vector<std::string> v = {};

        // All words to upper
        while (ss >> s)
        {
            s[0] = toupper(s[0]);
            v.push_back(s);
        }

        for (auto &&i : v)
        {
            std::string t = i;

            size_t pos = findUnicodeCharacter(t, L"é");
            if (pos != std::string::npos)
                t = replaceUnicodeCharacter(t, L"é", L"e");

            pos = findUnicodeCharacter(t, L"š");
            if (pos != std::string::npos)
                t = replaceUnicodeCharacter(t, L"š", L"s");

            pos = findUnicodeCharacter(t, L"á");
            if (pos != std::string::npos)
                t = replaceUnicodeCharacter(t, L"á", L"a");

            pos = findUnicodeCharacter(t, L"à");
            if (pos != std::string::npos)
                t = replaceUnicodeCharacter(t, L"à", L"a");

            pos = findUnicodeCharacter(t, L"⟩");
            if (pos != std::string::npos)
                t = replaceUnicodeCharacter(t, L"⟩", L"");

            pos = findUnicodeCharacter(t, L"’");
            if (pos != std::string::npos)
                t = replaceUnicodeCharacter(t, L"’", L"");

            pos = findUnicodeCharacter(t, L"™");
            if (pos != std::string::npos)
                t = replaceUnicodeCharacter(t, L"™", L"");

            pos = findUnicodeCharacter(t, L"±");
            if (pos != std::string::npos)
                t = replaceUnicodeCharacterWithString(t, L"±", "PlusMinus");

            pos = findUnicodeCharacter(t, L"№");
            if (pos != std::string::npos)
                t = replaceUnicodeCharacterWithString(t, L"№", "Number");

            pos = findUnicodeCharacter(t, L"⊗");
            if (pos != std::string::npos)
                t = replaceUnicodeCharacterWithString(t, L"⊗", "Times");

            pos = findUnicodeCharacter(t, L"ü");
            if (pos != std::string::npos)
                t = replaceUnicodeCharacterWithString(t, L"ü", "oo");

            pos = findUnicodeCharacter(t, L"√");
            if (pos != std::string::npos)
                t = replaceUnicodeCharacterWithString(t, L"√", "Sqrt");

            pos = findUnicodeCharacter(t, L"θ");
            if (pos != std::string::npos)
                t = replaceUnicodeCharacterWithString(t, L"θ", "Theta");

            pos = findUnicodeCharacter(t, L"С");
            if (pos != std::string::npos)
                t = replaceUnicodeCharacterWithString(t, L"С", "C");

            pos = findUnicodeCharacter(t, L"с");
            if (pos != std::string::npos)
                t = replaceUnicodeCharacterWithString(t, L"с", "c");

            pos = findUnicodeCharacter(t, L"Ж");
            if (pos != std::string::npos)
                t = replaceUnicodeCharacterWithString(t, L"Ж", "Z");

            if (t.find('|') != std::string::npos)
                t.erase(remove(t.begin(), t.end(), '|'), t.end());

            if (t.find('%') != std::string::npos)
                t.erase(remove(t.begin(), t.end(), '%'), t.end());

            if (t.find('`') != std::string::npos)
                t.erase(remove(t.begin(), t.end(), '`'), t.end());

            if (t.find('\"') != std::string::npos)
                t.erase(remove(t.begin(), t.end(), '\"'), t.end());

            if (t.find('#') != std::string::npos)
                t.erase(remove(t.begin(), t.end(), '#'), t.end());

            if (t.find(':') != std::string::npos)
                t.erase(remove(t.begin(), t.end(), ':'), t.end());

            if (t.find('.') != std::string::npos)
                t.erase(remove(t.begin(), t.end(), '.'), t.end());

            if (t.find('?') != std::string::npos)
                t.erase(remove(t.begin(), t.end(), '?'), t.end());

            if (t.find(',') != std::string::npos)
                t.erase(remove(t.begin(), t.end(), ','), t.end());

            if (t.find('\'') != std::string::npos)
                t.erase(remove(t.begin(), t.end(), '\''), t.end());

            if (t.find('<') != std::string::npos)
                t.erase(remove(t.begin(), t.end(), '<'), t.end());

            if (t.find('>') != std::string::npos)
                t.erase(remove(t.begin(), t.end(), '>'), t.end());

            if (t.find('*') != std::string::npos)
                t = replaceCharWithString(t, '*', "Times");

            if (t.find('^') != std::string::npos)
                t = replaceCharWithString(t, '^', "ToPower");

            if (t.find('+') != std::string::npos)
                t = replaceCharWithString(t, '+', "Plus");

            if (t.find('&') != std::string::npos)
                t = replaceCharWithString(t, '&', "And");

            if (t.find('\\') != std::string::npos)
                t.erase(remove(t.begin(), t.end(), '\\'), t.end());

            if (t.find('/') != std::string::npos)
                t.erase(remove(t.begin(), t.end(), '/'), t.end());

            if (t.find('-') != std::string::npos)
                t.erase(remove(t.begin(), t.end(), '-'), t.end());

            if (t.find('!') != std::string::npos && t.find('=') != std::string::npos)
                t = replaceStringWithString(t, "!=", "NotEqual");

            if (t.find('!') != std::string::npos)
                t.erase(remove(t.begin(), t.end(), '!'), t.end());

            if (t.find('=') != std::string::npos)
                t = replaceCharWithString(t, '=', "Equals");

            if (t.find('(') != std::string::npos)
                t.erase(remove(t.begin(), t.end(), '('), t.end());

            if (t.find(')') != std::string::npos)
                t.erase(remove(t.begin(), t.end(), ')'), t.end());

            if (t.find('\'') != std::string::npos)
                t.erase(remove(t.begin(), t.end(), '\''), t.end());

            t[0] = toupper(t[0]);

            res += t;
        }
    }

    return res;
}

static std::vector<rft_meta_csv> getCSVMetaProblemNames()
{
    std::vector<std::string> meta_csv_rows = getAllRowsCSVMetaProblemNames();
    std::vector<rft_meta_csv> meta_problems = {};

    // store problems as objects
    if (meta_csv_rows.size() > 0)
    {
        for (auto &&i : meta_csv_rows)
        {
            std::vector<std::string> tokens;
            std::string token = i;
            size_t pos = 0;

            while ((pos = token.find(';')) != std::string::npos)
            {
                std::string part = token.substr(0, pos);
                part.erase(0, part.find_first_not_of(" \t\n\r\f\v"));
                part.erase(part.find_last_not_of(" \t\n\r\f\v") + 1);
                tokens.push_back(part);
                token.erase(0, pos + 2);
            }
            token.erase(0, token.find_first_not_of(" \t\n\r\f\v"));
            token.erase(token.find_last_not_of(" \t\n\r\f\v") + 1);
            tokens.push_back(token);

            // Problem id adjusting
            std::string problem_number = tokens[1];
            tokens[1] = refactorProblemId(problem_number);

            // Title sanitization
            std::string problem_title = tokens[2];
            tokens[2] = sanitizeProblemName(problem_title);

            std::vector<std::string> topics = {};
            std::string topic = tokens[4];
            pos = 0;

            if (topic.size() > 0)
            {
                while ((pos = topic.find(',')) != std::string::npos)
                {
                    std::string part = topic.substr(0, pos);
                    part.erase(0, part.find_first_not_of(" \t\n\r\f\v"));
                    part.erase(part.find_last_not_of(" \t\n\r\f\v") + 1);
                    topics.push_back(part);
                    topic.erase(0, pos + 1);
                }
                topic.erase(0, topic.find_first_not_of(" \t\n\r\f\v"));
                topic.erase(topic.find_last_not_of(" \t\n\r\f\v") + 1);
                topics.push_back(topic);
            }

            rft_meta_csv meta_problem;
            meta_problem.competition_name = tokens[0].size() > 0 ? tokens[0] : "";
            meta_problem.problem_number = tokens[1].size() > 0 ? tokens[1] : "";
            meta_problem.problem_title = tokens[2].size() > 0 ? tokens[2] : "";
            meta_problem.difficulty = tokens[3].size() > 0 ? std::stoi(tokens[3]) : 0;
            meta_problem.algorithms = topics.size() > 0 ? topics : std::vector<std::string>();

            meta_problems.push_back(meta_problem);
        }
    }

    return meta_problems;

    // // sort
    // if (cf_problem_names.size() > 0)
    //     std::sort(cf_problem_names.begin(), cf_problem_names.end());
    // else
    //     std::cout << "File Empty!\n";
    //
    // // open file write
    // // out.open(codeforces_problem_names_file, std::ios_base::app);
    // out.open(CODEFORCES_PROBLEM_NAMES_FILE);
    // if (!out.is_open())
    // {
    //     std::cerr << "Error opening problem names file output: " << CODEFORCES_PROBLEM_NAMES_FILE << std::endl;
    //     return;
    // }
    //
    // // rewrite problem names to file
    // for (int i = 0; i < cf_problem_names.size(); i++)
    // {
    //     if (i < cf_problem_names.size() - 1)
    //         out << cf_problem_names[i] << "\n";
    //     else
    //         out << cf_problem_names[i];
    // }
    //
    // // store sanitized problem names
    // cf_problem_names.clear();
    // cf_problem_names = problem_names;
    //
    // // close output stream
    // if (out.is_open())
    //     out.close();

    // optional print
    // if (print_problems)
    // {
    //     std::cout << "CodeForces problem names:\n";

    //     for (auto &&i : cf_problem_names)
    //     {
    //         std::cout << i << "\n";
    //     }
    // }
}

static void insertPGMetaTable(rft_meta_csv rft_csv)
{
    std::string conn_str = getPGLeviathanConnectionString();

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "CALL PUBLIC.SP_META_INSERT($1, $2, $3, $4, $5)";

        worker.exec(sql, pqxx::params(rft_csv.competition_name,
                                      rft_csv.problem_number,
                                      rft_csv.problem_title,
                                      rft_csv.difficulty,
                                      rft_csv.algorithms));

        worker.commit();

        std::cout << "Transaction: " << sql << "\n";
        std::cout << "Call registered successfully.\n\n";
    }
    catch (const pqxx::sql_error &e)
    {
        std::cerr << "SQL error: " << e.what() << "\nQuery was: " << e.query() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

static void insertPGMetaTable(std::vector<rft_meta_csv> rft_csvs)
{
    std::string conn_str = getPGLeviathanConnectionString();

    try
    {
        for (auto &&rft_csv : rft_csvs)
        {
            pqxx::connection conn(conn_str);
            pqxx::work worker(conn);

            std::string sql = "CALL PUBLIC.SP_META_INSERT($1, $2, $3, $4, $5)";

            worker.exec(sql, pqxx::params(rft_csv.competition_name,
                                          rft_csv.problem_number,
                                          rft_csv.problem_title,
                                          rft_csv.difficulty,
                                          rft_csv.algorithms));

            worker.commit();

            std::cout << "Transaction: " << sql << "\n";
            std::cout << "Call registered successfully.\n\n";
        }
    }
    catch (const pqxx::sql_error &e)
    {
        std::cerr << "SQL error: " << e.what() << "\nQuery was: " << e.query() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
