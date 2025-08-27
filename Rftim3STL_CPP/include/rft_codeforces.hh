#pragma once
#include "rft_global_cpp.hh"
#include "rft_io.hh"
#include "rft_paths.hh"
#include "rft_postgre_sql.hh"
#include "rft_string.hh"
#include "rft_time.hh"
#include "rft_unit_test.hh"

struct rft_codeforces_csv
{
    std::string competition_name;
    int rank;
    int rating;
    std::string problem_number;
    std::string problem_title;
    std::string problem_description;
    std::string problem_input;
    int difficulty;
    std::vector<std::string> algorithms;
};

struct rft_codeforces_competition
{
    long id;
    std::string competition_name;
    std::string timestamp;
    int rank;
    int rating;
    std::string folder_path;
};

struct rft_codeforces_problem
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

struct rft_codeforces_solution
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

static const std::filesystem::path CODEFORCES_PROJECT_PATH = ACTIVE_PROJECT_PATH / "Rftim3CodeForces";
static const std::filesystem::path CODEFORCES_PROJECT_CMAKE_FILE = ACTIVE_PROJECT_PATH / "CMakeLists.txt";
static const std::filesystem::path CODEFORCES_PROBLEM_NAMES_FILE = CODEFORCES_PROJECT_PATH / TEMPLATES_DIRECTORY / "CodeForcesProblemNames.csv";
static const std::filesystem::path CODEFORCES_PROJECT_PROBLEMS_DIRECTORY_PATH = CODEFORCES_PROJECT_PATH / PROBLEMS_DIRECTORY;
static const std::filesystem::path CODEFORCES_PROBLEM_MAIN_HEADER_FILE_TEMPLATE = CODEFORCES_PROJECT_PATH / TEMPLATES_DIRECTORY / "CodeForcesMainHeaderFileTemplate.txt";
static const std::filesystem::path CODEFORCES_PROBLEM_MAIN_SOURCE_FILE_TEMPLATE = CODEFORCES_PROJECT_PATH / TEMPLATES_DIRECTORY / "CodeForcesMainSourceFileTemplate.txt";
static const std::filesystem::path CODEFORCES_PROBLEM_SOLUTION_FILE_TEMPLATE = CODEFORCES_PROJECT_PATH / TEMPLATES_DIRECTORY / "CodeForcesSolutionFileTemplate.txt";
static const std::filesystem::path CODEFORCES_PROBLEM_CMAKE_TEMPLATE_FILE = CODEFORCES_PROJECT_PATH / TEMPLATES_DIRECTORY / "CodeForcesCMakeListsTemplate.txt";
static const std::filesystem::path CODEFORCES_PROJECT_CMAKE_TEMPLATE_FILE = CODEFORCES_PROJECT_PATH / TEMPLATES_DIRECTORY / "CodeForcesProjectCMakeListsTemplate.txt";
static const std::filesystem::path CODEFORCES_PROBLEMS_DIRECTORY_PATH = ACTIVE_PROJECT_PATH.parent_path().parent_path() / "Rftim3CodeForces" / PROBLEMS_DIRECTORY;

// CSV
static void printCodeForcesCSV(rft_codeforces_csv cf_csv)
{
    std::cout << cf_csv.competition_name << "\n";
    std::cout << cf_csv.rank << "\n";
    std::cout << cf_csv.rating << "\n";
    std::cout << cf_csv.problem_number << "\n";
    std::cout << cf_csv.problem_title << "\n";
    std::cout << cf_csv.problem_description << "\n";
    std::cout << cf_csv.problem_input << "\n";
    std::cout << cf_csv.difficulty << "\n";
    for (int i = 0; i < cf_csv.algorithms.size(); i++)
    {
        if (i == cf_csv.algorithms.size() - 1)
            std::cout << cf_csv.algorithms[i] << "\n";
        else
            std::cout << cf_csv.algorithms[i] << ", ";
    }
}

static void printAllCodeForcesCSV(std::vector<rft_codeforces_csv> cf_csv)
{
    for (auto &&i : cf_csv)
    {
        printCodeForcesCSV(i);
    }
}

static std::vector<std::string> getAllRowsCSVCodeForcesProblemNames()
{
    static std::vector<std::string> v = {};

    // open file read
    in.open(CODEFORCES_PROBLEM_NAMES_FILE);
    if (!in.is_open())
    {
        std::cerr << "Error opening problem names file input: " << CODEFORCES_PROBLEM_NAMES_FILE << std::endl;
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
    if (input.find("cf_") == std::string::npos)
    {
        std::string res = "";
        res += "cf_";

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

static std::vector<rft_codeforces_csv> getCSVCodeForcesProblemNames()
{
    std::vector<std::string> cf_csv_rows = getAllRowsCSVCodeForcesProblemNames();
    std::vector<rft_codeforces_csv> cf_problems = {};

    // store problems as objects
    if (cf_csv_rows.size() > 0)
    {
        for (auto &&i : cf_csv_rows)
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

            rft_codeforces_csv cf_problem;
            cf_problem.competition_name = tokens[0].size() > 0 ? tokens[0] : "";
            cf_problem.problem_number = tokens[1].size() > 0 ? tokens[1] : "";
            cf_problem.problem_title = tokens[2].size() > 0 ? tokens[2] : "";
            cf_problem.difficulty = tokens[3].size() > 0 ? std::stoi(tokens[3]) : 0;
            cf_problem.algorithms = topics.size() > 0 ? topics : std::vector<std::string>();

            cf_problems.push_back(cf_problem);
        }
    }

    return cf_problems;
}

static void insertPGCodeForcesTable(rft_codeforces_csv rft_csv)
{
    std::string conn_str = getPGLeviathanConnectionString();

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "CALL PUBLIC.SP_CODEFORCES_INSERT($1, $2, $3, $4, $5)";

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

static void insertPGCodeForcesTable(std::vector<rft_codeforces_csv> rft_csvs)
{
    std::string conn_str = getPGLeviathanConnectionString();

    try
    {
        for (auto &&rft_csv : rft_csvs)
        {
            pqxx::connection conn(conn_str);
            pqxx::work worker(conn);

            std::string sql = "CALL PUBLIC.SP_CODEFORCES_INSERT($1, $2, $3, $4, $5)";

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

// Postgre
static void printCodeForcesCompetition(rft_codeforces_competition cf_comp)
{
    std::cout << "Id: " << cf_comp.id << "\n";
    std::cout << "Competition name: " << cf_comp.competition_name << "\n";
    std::cout << "Timestamp: " << cf_comp.timestamp << "\n";
    std::cout << "Rank: " << cf_comp.rank << "\n";
    std::cout << "Rating: " << cf_comp.rating << "\n";
    std::cout << "Folder path: " << cf_comp.folder_path << "\n";
}

static void printCodeForcesCompetitions(std::vector<rft_codeforces_competition> cf_comp)
{
    for (auto &&i : cf_comp)
    {
        printCodeForcesCompetition(i);
    }
}

static void printCodeForcesProblem(rft_codeforces_problem cf_prob)
{
    std::cout << "Id: " << cf_prob.id << "\n";
    std::cout << "Competition id: " << cf_prob.competition_id << "\n";
    std::cout << "Problem number: " << cf_prob.problem_number << "\n";
    std::cout << "Problem title: " << cf_prob.problem_title << "\n";
    std::cout << "Problem description: " << cf_prob.problem_description << "\n";
    std::cout << "Problem input: " << cf_prob.problem_input << "\n";
    std::cout << "Difficulty: " << cf_prob.difficulty << "\n";
    std::cout << "Folder path: " << cf_prob.folder_path << "\n";
}

static void printCodeForcesProblems(std::vector<rft_codeforces_problem> cf_prob)
{
    for (auto &&i : cf_prob)
    {
        printCodeForcesProblem(i);
    }
}

static void printCodeForcesSolution(rft_codeforces_solution cf_sol)
{
    std::cout << "Id: " << cf_sol.id << "\n";
    std::cout << "Problem id: " << cf_sol.problem_id << "\n";
    std::cout << "Solution name: " << cf_sol.solution_name << "\n";
    std::cout << "Test status: " << cf_sol.test_status << "\n";
    std::cout << "Runtime: " << cf_sol.runtime << "\n";
    std::cout << "Memory: " << cf_sol.memory << "\n";
    std::cout << "Algorithms: ";
    for (int i = 0; i < cf_sol.algorithms.size(); i++)
    {
        if (i == cf_sol.algorithms.size() - 1)
            std::cout << cf_sol.algorithms[i] << ";";
        else
            std::cout << cf_sol.algorithms[i] << ", ";
    }
    std::cout << "\n";
    std::cout << "File path: " << cf_sol.file_path << "\n";
}

static void printCodeForcesSolutions(std::vector<rft_codeforces_solution> cf_sol)
{
    for (auto &&i : cf_sol)
    {
        printCodeForcesSolution(i);
    }
}

static void insertPGCodeForcesCompetition(rft_codeforces_competition cf_comp)
{
    std::string conn_str = getPGLeviathanConnectionString();

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "CALL PUBLIC.SP_CODEFORCES_COMPETITION_INSERT($1, $2, $3, $4, $5)";

        worker.exec(sql, pqxx::params(cf_comp.competition_name,
                                      cf_comp.timestamp,
                                      cf_comp.rank,
                                      cf_comp.rating,
                                      cf_comp.folder_path));

        worker.commit();

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

static void insertPGCodeForcesProblem(rft_codeforces_problem cf_prob)
{
    std::string conn_str = getPGLeviathanConnectionString();

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "CALL PUBLIC.SP_CODEFORCES_PROBLEM_INSERT($1, $2, $3, $4, $5, $6, $7)";

        worker.exec(sql, pqxx::params(cf_prob.competition_id,
                                      cf_prob.problem_number,
                                      cf_prob.problem_title,
                                      cf_prob.problem_description,
                                      cf_prob.problem_input,
                                      cf_prob.difficulty,
                                      cf_prob.folder_path));

        worker.commit();

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

static void insertPGCodeForcesSolution(rft_codeforces_solution cf_sol)
{
    std::string conn_str = getPGLeviathanConnectionString();

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "CALL PUBLIC.SP_CODEFORCES_SOLUTION_INSERT($1, $2, $3, $4, $5, $6, $7)";

        worker.exec(sql, pqxx::params(cf_sol.problem_id,
                                      cf_sol.solution_name,
                                      cf_sol.test_status,
                                      cf_sol.runtime,
                                      cf_sol.memory,
                                      cf_sol.algorithms,
                                      cf_sol.file_path));

        worker.commit();

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

static rft_codeforces_competition getPGCodeForcesCompetition(std::string cf_comp)
{
    std::string conn_str = getPGLeviathanConnectionString();
    rft_codeforces_competition rft_cf_comp;

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "SELECT * FROM FN_CODEFORCES_COMPETITIONS_SELECT_BY_COMPETITION_NAME ($1);";
        pqxx::result res = worker.exec(sql, pqxx::params(cf_comp));

        if (res.size() > 0)
        {
            rft_cf_comp.id = res[0]["id"].as<long>();
            rft_cf_comp.competition_name = res[0]["competition_name"].as<std::string>();
            rft_cf_comp.timestamp = res[0]["timestamp"].as<std::string>();
            rft_cf_comp.rank = res[0]["rank"].as<int>();
            rft_cf_comp.rating = res[0]["rating"].as<int>();
            rft_cf_comp.folder_path = res[0]["folder_path"].as<std::string>();
        }

        worker.commit();
    }
    catch (const pqxx::sql_error &e)
    {
        std::cerr << "SQL error: " << e.what() << "\nQuery was: " << e.query() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return rft_cf_comp;
}

static rft_codeforces_problem getPGCodeForcesProblem(std::string cf_prob)
{
    std::string conn_str = getPGLeviathanConnectionString();
    rft_codeforces_problem rft_cf_prob;

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "SELECT * FROM FN_CODEFORCES_PROBLEMS_SELECT_BY_PROBLEM_NUMBER ($1)";
        pqxx::result res = worker.exec(sql, pqxx::params(cf_prob));

        if (res.size() > 0)
        {
            rft_cf_prob.id = res[0]["id"].as<long>();
            rft_cf_prob.competition_id = res[0]["competition_id"].as<long>();
            rft_cf_prob.problem_number = res[0]["problem_number"].as<std::string>();
            rft_cf_prob.problem_title = res[0]["problem_title"].as<std::string>();
            rft_cf_prob.problem_description = res[0]["problem_description"].as<std::string>();
            rft_cf_prob.problem_input = res[0]["problem_input"].as<std::string>();
            rft_cf_prob.difficulty = res[0]["difficulty"].as<int>();
            rft_cf_prob.folder_path = res[0]["folder_path"].as<std::string>();
        }

        worker.commit();
    }
    catch (const pqxx::sql_error &e)
    {
        std::cerr << "SQL error: " << e.what() << "\nQuery was: " << e.query() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return rft_cf_prob;
}

static rft_codeforces_solution getPGCodeForcesSolution(std::string cf_sol)
{
    std::string conn_str = getPGLeviathanConnectionString();
    rft_codeforces_solution rft_cf_sol;

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "SELECT * FROM FN_CODEFORCES_SOLUTIONS_SELECT_BY_SOLUTION_NAME ($1)";
        pqxx::result res = worker.exec(sql, pqxx::params(cf_sol));

        if (res.size() > 0)
        {
            rft_cf_sol.id = res[0]["id"].as<long>();
            rft_cf_sol.problem_id = res[0]["problem_id"].as<long>();
            rft_cf_sol.solution_name = res[0]["solution_name"].as<std::string>();
            rft_cf_sol.test_status = res[0]["test_status"].as<bool>();
            rft_cf_sol.runtime = res[0]["runtime"].as<double>();
            rft_cf_sol.memory = res[0]["memory"].as<double>();
            std::vector<std::string> algos = {};
            {
                std::string algorithms = res[0]["algorithms"].as<std::string>();
                std::string s = algorithms;
                s.erase(remove(s.begin(), s.end(), '{'), s.end());
                s.erase(remove(s.begin(), s.end(), '}'), s.end());
                std::stringstream ss(s);
                std::string t = "";
                while (getline(ss, t, ','))
                {
                    algos.push_back(t);
                }
            }
            rft_cf_sol.algorithms = algos;
            rft_cf_sol.file_path = res[0]["file_path"].as<std::string>();
        }

        worker.commit();
    }
    catch (const pqxx::sql_error &e)
    {
        std::cerr << "SQL error: " << e.what() << "\nQuery was: " << e.query() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return rft_cf_sol;
}

static void insertPGCodeForcesFullProblem(rft_codeforces_csv cf_csv)
{
    rft_codeforces_competition cf_comp = getPGCodeForcesCompetition(cf_csv.competition_name);
    rft_codeforces_problem cf_prob = getPGCodeForcesProblem(cf_csv.problem_number);

    // create competition
    if (cf_comp.competition_name == "")
    {
        std::filesystem::path comp_dir = CODEFORCES_PROJECT_PROBLEMS_DIRECTORY_PATH / cf_csv.competition_name;
        if (!std::filesystem::exists(comp_dir))
            std::filesystem::create_directory(comp_dir);

        cf_comp.competition_name = cf_csv.competition_name;
        cf_comp.timestamp = getCurrentTimestamp();
        cf_comp.rank = cf_csv.rank;
        cf_comp.rating = cf_csv.rating;
        cf_comp.folder_path = comp_dir.string();
        insertPGCodeForcesCompetition(cf_comp);
        cf_comp = getPGCodeForcesCompetition(cf_csv.competition_name);
    }

    // create problem
    if (cf_prob.problem_number == "")
    {
        cf_prob.competition_id = cf_comp.id;
        cf_prob.problem_number = cf_csv.problem_number;
        cf_prob.problem_title = cf_csv.problem_title;
        cf_prob.problem_description = cf_csv.problem_description;
        cf_prob.problem_input = cf_csv.problem_input;
        cf_prob.difficulty = cf_csv.difficulty;
        cf_prob.folder_path = (std::filesystem::path(cf_comp.folder_path) / cf_prob.problem_number).string();
        insertPGCodeForcesProblem(cf_prob);
        cf_prob = getPGCodeForcesProblem(cf_csv.problem_number);
    }

    // create problem directory
    std::filesystem::path prob_dir = std::filesystem::path(cf_comp.folder_path) / cf_csv.problem_number;
    if (!std::filesystem::exists(prob_dir))
        std::filesystem::create_directory(prob_dir);

    // create io files
    std::filesystem::path input_file = prob_dir / std::filesystem::path(cf_prob.problem_number + "_Input.txt");
    if (!std::filesystem::exists(input_file))
    {
        std::ofstream new_input_file;
        new_input_file.open(input_file, std::fstream::trunc);
        new_input_file << cf_prob.problem_input;
        new_input_file.close();
    }

    std::filesystem::path output_file = prob_dir / std::filesystem::path(cf_prob.problem_number + "_Output.txt");
    if (!std::filesystem::exists(output_file))
    {
        std::ofstream new_output_file;
        new_output_file.open(output_file, std::fstream::trunc);
        new_output_file.close();
    }

    // create main.hh
    std::filesystem::path header_filename = prob_dir / std::filesystem::path("main.hh");
    if (!std::filesystem::exists(header_filename))
    {
        std::fstream fp;
        fp.open(CODEFORCES_PROBLEM_MAIN_HEADER_FILE_TEMPLATE, std::ios::in);
        std::string a = "";
        std::vector<std::string> header_content = {};

        while (getline(fp, a))
        {
            header_content.push_back(a);
        }
        fp.close();

        std::ofstream new_header_file;
        new_header_file.open(header_filename, std::fstream::trunc);

        for (auto &&j : header_content)
        {
            std::string t = j;
            std::string cf_sol = cf_prob.problem_number + "_0";

            while (t.find("[sol]") != std::string::npos)
            {
                t.replace(t.find("[sol]"), 5, cf_sol);
            }

            new_header_file << t << "\n";
        }

        new_header_file.close();
    }

    // create main.cc
    std::filesystem::path source_filename = prob_dir / std::filesystem::path("main.cc");
    if (!std::filesystem::exists(source_filename))
    {
        std::fstream fp;
        fp.open(CODEFORCES_PROBLEM_MAIN_SOURCE_FILE_TEMPLATE, std::ios::in);
        std::string a = "";
        std::vector<std::string> source_content = {};

        while (getline(fp, a))
        {
            source_content.push_back(a);
        }
        fp.close();

        std::ofstream new_source_file;
        new_source_file.open(source_filename, std::fstream::trunc);

        for (auto &&j : source_content)
        {
            std::string t = j;
            std::string cf_sol = cf_csv.problem_number + "_0";

            while (t.find("[sol]") != std::string::npos)
            {
                t.replace(t.find("[sol]"), 5, cf_sol);
            }

            new_source_file << t << "\n";
        }

        new_source_file.close();
    }

    // create solution
    std::filesystem::path solution_filename = prob_dir / std::filesystem::path(cf_csv.problem_number + "_0.cc");
    if (!std::filesystem::exists(solution_filename))
    {
        std::fstream fp;
        fp.open(CODEFORCES_PROBLEM_SOLUTION_FILE_TEMPLATE, std::ios::in);
        std::string a = "";
        std::vector<std::string> solution_content = {};

        while (getline(fp, a))
        {
            solution_content.push_back(a);
        }
        fp.close();

        std::ofstream new_solution_file;
        new_solution_file.open(solution_filename, std::fstream::trunc);

        for (auto &&j : solution_content)
        {
            std::string t = j;
            std::string cf_sol = cf_csv.problem_number + "_0";

            while (t.find("[sol]") != std::string::npos)
            {
                t.replace(t.find("[sol]"), 5, cf_sol);
            }

            new_solution_file << t << "\n";
        }

        new_solution_file.close();
    }

    if (getPGCodeForcesSolution(cf_prob.problem_number + "_0.cc").solution_name == "")
    {
        rft_codeforces_solution cf_sol;
        cf_sol.problem_id = cf_prob.id;
        cf_sol.solution_name = cf_csv.problem_number + "_0.cc";
        cf_sol.test_status = false;
        cf_sol.runtime = 0.0;
        cf_sol.memory = 0.0;
        cf_sol.algorithms = cf_csv.algorithms;
        cf_sol.file_path = (std::filesystem::path(cf_comp.folder_path) / cf_prob.problem_number / (cf_csv.problem_number + "_0.cc")).string();
        insertPGCodeForcesSolution(cf_sol);
    }

    // create cmakelists
    std::filesystem::path cmake_filename = prob_dir / std::filesystem::path("CMakeLists.txt");
    if (!std::filesystem::exists(cmake_filename))
    {
        std::fstream fp;
        fp.open(CODEFORCES_PROBLEM_CMAKE_TEMPLATE_FILE, std::ios::in);
        std::string a = "";
        std::vector<std::string> cmake_content = {};

        while (getline(fp, a))
        {
            cmake_content.push_back(a);
        }
        fp.close();

        std::ofstream new_cmake_file;
        new_cmake_file.open(cmake_filename, std::fstream::trunc);

        for (auto &&j : cmake_content)
        {
            std::string t = j;
            std::string cf_prob = cf_csv.problem_number;

            while (t.find("[prob]") != std::string::npos)
            {
                t.replace(t.find("[prob]"), 6, cf_prob);
            }

            new_cmake_file << t << "\n";
        }

        new_cmake_file.close();

        // link cmake
        in.open(CODEFORCES_PROJECT_CMAKE_TEMPLATE_FILE);
        if (!in.is_open())
        {
            std::cerr << "Error opening project cmake file" << std::endl;
            return;
        }

        out.open(CODEFORCES_PROJECT_CMAKE_FILE, std::ios_base::app);
        if (!out.is_open())
        {
            std::cerr << "Error opening project cmake file" << std::endl;
            return;
        }

        in.clear();                 // Clear any error flags
        in.seekg(0, std::ios::beg); // Move stream buffer back to beginning
        while (!in.eof())
        {
            std::string t = "";
            std::getline(in, t);
            while (t.find("[comp]") != std::string::npos)
            {
                t.replace(t.find("[comp]"), 6, cf_csv.competition_name);
            }

            while (t.find("[prob]") != std::string::npos)
            {
                t.replace(t.find("[prob]"), 6, cf_csv.problem_number);
            }

            out << t << "\n";
        }

        in.close();
        out.close();
    }
}

// IO
static void openCodeForcesProblemIOFiles(std::string problem_name)
{
    rft_codeforces_problem cf_prob = getPGCodeForcesProblem(problem_name);

    std::filesystem::path input_filename = std::filesystem::path(cf_prob.folder_path) / std::filesystem::path(cf_prob.problem_number + "_Input.txt");
    std::filesystem::path output_filename = std::filesystem::path(cf_prob.folder_path) / std::filesystem::path(cf_prob.problem_number + "_Output.txt");

    in.open(input_filename);
    if (!in.is_open())
    {
        std::cerr << "Error opening input file: " << input_filename << std::endl;
        return;
    }

    out.open(output_filename);
    if (!out.is_open())
    {
        std::cerr << "Error opening output file: " << output_filename << std::endl;
        return;
    }
}

static std::string refactorProblemNumber(std::string current_file)
{
    std::string problem_name = "";
    size_t last_pos = current_file.find_last_of('\\');
    
    if (last_pos != std::string::npos)
    {
        size_t prev_pos = current_file.find_last_of('\\', last_pos - 1);
        if (prev_pos != std::string::npos)
            problem_name = current_file.substr(prev_pos + 1, last_pos - prev_pos - 1);
        else
            problem_name = current_file.substr(0, last_pos);
    }

    return problem_name;
}


