#pragma once
#include "rft_global_cpp.hh"
#include "rft_io.hh"
#include "rft_paths.hh"
#include "rft_postgre_sql.hh"
#include "rft_string.hh"
#include "rft_time.hh"
#include "rft_unit_test.hh"

struct rft_leetcode_csv
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

struct rft_leetcode_competition
{
    long id;
    std::string competition_name;
    std::string timestamp;
    int rank;
    int rating;
    std::string folder_path;
};

struct rft_leetcode_problem
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

struct rft_leetcode_solution
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

static const std::filesystem::path LEETCODE_PROJECT_PATH = ACTIVE_PROJECT_PATH / "Rftim3LeetCode";
static const std::filesystem::path LEETCODE_PROJECT_CMAKE_FILE = ACTIVE_PROJECT_PATH / "CMakeLists.txt";
static const std::filesystem::path LEETCODE_PROBLEM_NAMES_FILE = LEETCODE_PROJECT_PATH / TEMPLATES_DIRECTORY / "LeetCodeProblemNames.csv";
static const std::filesystem::path LEETCODE_PROJECT_PROBLEMS_DIRECTORY_PATH = LEETCODE_PROJECT_PATH / PROBLEMS_DIRECTORY;
static const std::filesystem::path LEETCODE_PROBLEM_MAIN_HEADER_FILE_TEMPLATE = LEETCODE_PROJECT_PATH / TEMPLATES_DIRECTORY / "LeetCodeMainHeaderFileTemplate.txt";
static const std::filesystem::path LEETCODE_PROBLEM_MAIN_SOURCE_FILE_TEMPLATE = LEETCODE_PROJECT_PATH / TEMPLATES_DIRECTORY / "LeetCodeMainSourceFileTemplate.txt";
static const std::filesystem::path LEETCODE_PROBLEM_SOLUTION_FILE_TEMPLATE = LEETCODE_PROJECT_PATH / TEMPLATES_DIRECTORY / "LeetCodeSolutionFileTemplate.txt";
static const std::filesystem::path LEETCODE_PROBLEM_CMAKE_TEMPLATE_FILE = LEETCODE_PROJECT_PATH / TEMPLATES_DIRECTORY / "LeetCodeCMakeListsTemplate.txt";
static const std::filesystem::path LEETCODE_PROJECT_CMAKE_TEMPLATE_FILE = LEETCODE_PROJECT_PATH / TEMPLATES_DIRECTORY / "LeetCodeProjectCMakeListsTemplate.txt";
static const std::filesystem::path LEETCODE_PROBLEMS_DIRECTORY_PATH = ACTIVE_PROJECT_PATH.parent_path().parent_path() / "Rftim3LeetCode" / PROBLEMS_DIRECTORY;

// CSV
static void printLeetCodeCSV(rft_leetcode_csv lc_csv)
{
    std::cout << lc_csv.competition_name << "\n";
    std::cout << lc_csv.rank << "\n";
    std::cout << lc_csv.rating << "\n";
    std::cout << lc_csv.problem_number << "\n";
    std::cout << lc_csv.problem_title << "\n";
    std::cout << lc_csv.problem_description << "\n";
    std::cout << lc_csv.problem_input << "\n";
    std::cout << lc_csv.difficulty << "\n";
    for (int i = 0; i < lc_csv.algorithms.size(); i++)
    {
        if (i == lc_csv.algorithms.size() - 1)
            std::cout << lc_csv.algorithms[i] << "\n";
        else
            std::cout << lc_csv.algorithms[i] << ", ";
    }
}

static void printAllLeetCodeCSV(std::vector<rft_leetcode_csv> lc_csv)
{
    for (auto &&i : lc_csv)
    {
        printLeetCodeCSV(i);
    }
}

static std::vector<std::string> getAllRowsCSVLeetCodeProblemNames()
{
    static std::vector<std::string> v = {};

    // open file read
    in.open(LEETCODE_PROBLEM_NAMES_FILE);
    if (!in.is_open())
    {
        std::cerr << "Error opening problem names file input: " << LEETCODE_PROBLEM_NAMES_FILE << std::endl;
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
    if (input.find("lc_") == std::string::npos)
    {
        std::string res = "";
        res += "lc_";

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

static std::vector<rft_leetcode_csv> getCSVLeetCodeProblemNames()
{
    std::vector<std::string> lc_csv_rows = getAllRowsCSVLeetCodeProblemNames();
    std::vector<rft_leetcode_csv> lc_problems = {};

    // store problems as objects
    if (lc_csv_rows.size() > 0)
    {
        for (auto &&i : lc_csv_rows)
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

            rft_leetcode_csv lc_problem;
            lc_problem.competition_name = tokens[0].size() > 0 ? tokens[0] : "";
            lc_problem.problem_number = tokens[1].size() > 0 ? tokens[1] : "";
            lc_problem.problem_title = tokens[2].size() > 0 ? tokens[2] : "";
            lc_problem.difficulty = tokens[3].size() > 0 ? std::stoi(tokens[3]) : 0;
            lc_problem.algorithms = topics.size() > 0 ? topics : std::vector<std::string>();

            lc_problems.push_back(lc_problem);
        }
    }

    return lc_problems;
}

static void insertPGLeetCodeTable(rft_leetcode_csv rft_csv)
{
    std::string conn_str = getPGLeviathanConnectionString();

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "CALL PUBLIC.SP_LEETCODE_INSERT($1, $2, $3, $4, $5)";

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

static void insertPGLeetCodeTable(std::vector<rft_leetcode_csv> rft_csvs)
{
    std::string conn_str = getPGLeviathanConnectionString();

    try
    {
        for (auto &&rft_csv : rft_csvs)
        {
            pqxx::connection conn(conn_str);
            pqxx::work worker(conn);

            std::string sql = "CALL PUBLIC.SP_LEETCODE_INSERT($1, $2, $3, $4, $5)";

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
static void printLeetCodeCompetition(rft_leetcode_competition lc_comp)
{
    std::cout << "Id: " << lc_comp.id << "\n";
    std::cout << "Competition name: " << lc_comp.competition_name << "\n";
    std::cout << "Timestamp: " << lc_comp.timestamp << "\n";
    std::cout << "Rank: " << lc_comp.rank << "\n";
    std::cout << "Rating: " << lc_comp.rating << "\n";
    std::cout << "Folder path: " << lc_comp.folder_path << "\n";
}

static void printLeetCodeCompetitions(std::vector<rft_leetcode_competition> lc_comp)
{
    for (auto &&i : lc_comp)
    {
        printLeetCodeCompetition(i);
    }
}

static void printLeetCodeProblem(rft_leetcode_problem lc_prob)
{
    std::cout << "Id: " << lc_prob.id << "\n";
    std::cout << "Competition id: " << lc_prob.competition_id << "\n";
    std::cout << "Problem number: " << lc_prob.problem_number << "\n";
    std::cout << "Problem title: " << lc_prob.problem_title << "\n";
    std::cout << "Problem description: " << lc_prob.problem_description << "\n";
    std::cout << "Problem input: " << lc_prob.problem_input << "\n";
    std::cout << "Difficulty: " << lc_prob.difficulty << "\n";
    std::cout << "Folder path: " << lc_prob.folder_path << "\n";
}

static void printLeetCodeProblems(std::vector<rft_leetcode_problem> lc_prob)
{
    for (auto &&i : lc_prob)
    {
        printLeetCodeProblem(i);
    }
}

static void printLeetCodeSolution(rft_leetcode_solution lc_sol)
{
    std::cout << "Id: " << lc_sol.id << "\n";
    std::cout << "Problem id: " << lc_sol.problem_id << "\n";
    std::cout << "Solution name: " << lc_sol.solution_name << "\n";
    std::cout << "Test status: " << lc_sol.test_status << "\n";
    std::cout << "Runtime: " << lc_sol.runtime << "\n";
    std::cout << "Memory: " << lc_sol.memory << "\n";
    std::cout << "Algorithms: ";
    for (int i = 0; i < lc_sol.algorithms.size(); i++)
    {
        if (i == lc_sol.algorithms.size() - 1)
            std::cout << lc_sol.algorithms[i] << ";";
        else
            std::cout << lc_sol.algorithms[i] << ", ";
    }
    std::cout << "\n";
    std::cout << "File path: " << lc_sol.file_path << "\n";
}

static void printLeetCodeSolutions(std::vector<rft_leetcode_solution> lc_sol)
{
    for (auto &&i : lc_sol)
    {
        printLeetCodeSolution(i);
    }
}

static void insertPGLeetCodeCompetition(rft_leetcode_competition lc_comp)
{
    std::string conn_str = getPGLeviathanConnectionString();

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "CALL PUBLIC.SP_LEETCODE_COMPETITION_INSERT($1, $2, $3, $4, $5)";

        worker.exec(sql, pqxx::params(lc_comp.competition_name,
                                      lc_comp.timestamp,
                                      lc_comp.rank,
                                      lc_comp.rating,
                                      lc_comp.folder_path));

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

static void insertPGLeetCodeProblem(rft_leetcode_problem lc_prob)
{
    std::string conn_str = getPGLeviathanConnectionString();

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "CALL PUBLIC.SP_LEETCODE_PROBLEM_INSERT($1, $2, $3, $4, $5, $6, $7)";

        worker.exec(sql, pqxx::params(lc_prob.competition_id,
                                      lc_prob.problem_number,
                                      lc_prob.problem_title,
                                      lc_prob.problem_description,
                                      lc_prob.problem_input,
                                      lc_prob.difficulty,
                                      lc_prob.folder_path));

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

static void insertPGLeetCodeSolution(rft_leetcode_solution lc_sol)
{
    std::string conn_str = getPGLeviathanConnectionString();

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "CALL PUBLIC.SP_LEETCODE_SOLUTION_INSERT($1, $2, $3, $4, $5, $6, $7)";

        worker.exec(sql, pqxx::params(lc_sol.problem_id,
                                      lc_sol.solution_name,
                                      lc_sol.test_status,
                                      lc_sol.runtime,
                                      lc_sol.memory,
                                      lc_sol.algorithms,
                                      lc_sol.file_path));

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

static rft_leetcode_competition getPGLeetCodeCompetition(std::string lc_comp)
{
    std::string conn_str = getPGLeviathanConnectionString();
    rft_leetcode_competition rft_lc_comp;

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "SELECT * FROM FN_LEETCODE_COMPETITIONS_SELECT_BY_COMPETITION_NAME ($1);";
        pqxx::result res = worker.exec(sql, pqxx::params(lc_comp));

        if (res.size() > 0)
        {
            rft_lc_comp.id = res[0]["id"].as<long>();
            rft_lc_comp.competition_name = res[0]["competition_name"].as<std::string>();
            rft_lc_comp.timestamp = res[0]["timestamp"].as<std::string>();
            rft_lc_comp.rank = res[0]["rank"].as<int>();
            rft_lc_comp.rating = res[0]["rating"].as<int>();
            rft_lc_comp.folder_path = res[0]["folder_path"].as<std::string>();
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

    return rft_lc_comp;
}

static rft_leetcode_problem getPGLeetCodeProblem(std::string lc_prob)
{
    std::string conn_str = getPGLeviathanConnectionString();
    rft_leetcode_problem rft_lc_prob;

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "SELECT * FROM FN_LEETCODE_PROBLEMS_SELECT_BY_PROBLEM_NUMBER ($1)";
        pqxx::result res = worker.exec(sql, pqxx::params(lc_prob));

        if (res.size() > 0)
        {
            rft_lc_prob.id = res[0]["id"].as<long>();
            rft_lc_prob.competition_id = res[0]["competition_id"].as<long>();
            rft_lc_prob.problem_number = res[0]["problem_number"].as<std::string>();
            rft_lc_prob.problem_title = res[0]["problem_title"].as<std::string>();
            rft_lc_prob.problem_description = res[0]["problem_description"].as<std::string>();
            rft_lc_prob.problem_input = res[0]["problem_input"].as<std::string>();
            rft_lc_prob.difficulty = res[0]["difficulty"].as<int>();
            rft_lc_prob.folder_path = res[0]["folder_path"].as<std::string>();
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

    return rft_lc_prob;
}

static rft_leetcode_solution getPGLeetCodeSolution(std::string lc_sol)
{
    std::string conn_str = getPGLeviathanConnectionString();
    rft_leetcode_solution rft_lc_sol;

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "SELECT * FROM FN_LEETCODE_SOLUTIONS_SELECT_BY_SOLUTION_NAME ($1)";
        pqxx::result res = worker.exec(sql, pqxx::params(lc_sol));

        if (res.size() > 0)
        {
            rft_lc_sol.id = res[0]["id"].as<long>();
            rft_lc_sol.problem_id = res[0]["problem_id"].as<long>();
            rft_lc_sol.solution_name = res[0]["solution_name"].as<std::string>();
            rft_lc_sol.test_status = res[0]["test_status"].as<bool>();
            rft_lc_sol.runtime = res[0]["runtime"].as<double>();
            rft_lc_sol.memory = res[0]["memory"].as<double>();
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
            rft_lc_sol.algorithms = algos;
            rft_lc_sol.file_path = res[0]["file_path"].as<std::string>();
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

    return rft_lc_sol;
}

static void insertPGLeetCodeFullProblem(rft_leetcode_csv lc_csv)
{
    rft_leetcode_competition lc_comp = getPGLeetCodeCompetition(lc_csv.competition_name);
    rft_leetcode_problem lc_prob = getPGLeetCodeProblem(lc_csv.problem_number);

    // create competition
    if (lc_comp.competition_name == "")
    {
        std::filesystem::path comp_dir = LEETCODE_PROJECT_PROBLEMS_DIRECTORY_PATH / lc_csv.competition_name;
        if (!std::filesystem::exists(comp_dir))
            std::filesystem::create_directory(comp_dir);

        lc_comp.competition_name = lc_csv.competition_name;
        lc_comp.timestamp = getCurrentTimestamp();
        lc_comp.rank = lc_csv.rank;
        lc_comp.rating = lc_csv.rating;
        lc_comp.folder_path = comp_dir.string();
        insertPGLeetCodeCompetition(lc_comp);
        lc_comp = getPGLeetCodeCompetition(lc_csv.competition_name);
    }

    // create problem
    if (lc_prob.problem_number == "")
    {
        lc_prob.competition_id = lc_comp.id;
        lc_prob.problem_number = lc_csv.problem_number;
        lc_prob.problem_title = lc_csv.problem_title;
        lc_prob.problem_description = lc_csv.problem_description;
        lc_prob.problem_input = lc_csv.problem_input;
        lc_prob.difficulty = lc_csv.difficulty;
        lc_prob.folder_path = (std::filesystem::path(lc_comp.folder_path) / lc_prob.problem_number).string();
        insertPGLeetCodeProblem(lc_prob);
        lc_prob = getPGLeetCodeProblem(lc_csv.problem_number);
    }

    // create problem directory
    std::filesystem::path prob_dir = std::filesystem::path(lc_comp.folder_path) / lc_csv.problem_number;
    if (!std::filesystem::exists(prob_dir))
        std::filesystem::create_directory(prob_dir);

    // create io files
    std::filesystem::path input_file = prob_dir / std::filesystem::path(lc_prob.problem_number + "_Input.txt");
    if (!std::filesystem::exists(input_file))
    {
        std::ofstream new_input_file;
        new_input_file.open(input_file, std::fstream::trunc);
        new_input_file << lc_prob.problem_input;
        new_input_file.close();
    }

    std::filesystem::path output_file = prob_dir / std::filesystem::path(lc_prob.problem_number + "_Output.txt");
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
        fp.open(LEETCODE_PROBLEM_MAIN_HEADER_FILE_TEMPLATE, std::ios::in);
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
            std::string lc_sol = lc_prob.problem_number + "_0";

            while (t.find("[sol]") != std::string::npos)
            {
                t.replace(t.find("[sol]"), 5, lc_sol);
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
        fp.open(LEETCODE_PROBLEM_MAIN_SOURCE_FILE_TEMPLATE, std::ios::in);
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
            std::string lc_sol = lc_csv.problem_number + "_0";

            while (t.find("[sol]") != std::string::npos)
            {
                t.replace(t.find("[sol]"), 5, lc_sol);
            }

            new_source_file << t << "\n";
        }

        new_source_file.close();
    }

    // create solution
    std::filesystem::path solution_filename = prob_dir / std::filesystem::path(lc_csv.problem_number + "_0.cc");
    if (!std::filesystem::exists(solution_filename))
    {
        std::fstream fp;
        fp.open(LEETCODE_PROBLEM_SOLUTION_FILE_TEMPLATE, std::ios::in);
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
            std::string lc_sol = lc_csv.problem_number + "_0";

            while (t.find("[sol]") != std::string::npos)
            {
                t.replace(t.find("[sol]"), 5, lc_sol);
            }

            new_solution_file << t << "\n";
        }

        new_solution_file.close();
    }

    if (getPGLeetCodeSolution(lc_prob.problem_number + "_0.cc").solution_name == "")
    {
        rft_leetcode_solution lc_sol;
        lc_sol.problem_id = lc_prob.id;
        lc_sol.solution_name = lc_csv.problem_number + "_0.cc";
        lc_sol.test_status = false;
        lc_sol.runtime = 0.0;
        lc_sol.memory = 0.0;
        lc_sol.algorithms = lc_csv.algorithms;
        lc_sol.file_path = (std::filesystem::path(lc_comp.folder_path) / lc_prob.problem_number / (lc_csv.problem_number + "_0.cc")).string();
        insertPGLeetCodeSolution(lc_sol);
    }

    // create cmakelists
    std::filesystem::path cmake_filename = prob_dir / std::filesystem::path("CMakeLists.txt");
    if (!std::filesystem::exists(cmake_filename))
    {
        std::fstream fp;
        fp.open(LEETCODE_PROBLEM_CMAKE_TEMPLATE_FILE, std::ios::in);
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
            std::string lc_prob = lc_csv.problem_number;

            while (t.find("[prob]") != std::string::npos)
            {
                t.replace(t.find("[prob]"), 6, lc_prob);
            }

            new_cmake_file << t << "\n";
        }

        new_cmake_file.close();

        // link cmake
        in.open(LEETCODE_PROJECT_CMAKE_TEMPLATE_FILE);
        if (!in.is_open())
        {
            std::cerr << "Error opening project cmake file" << std::endl;
            return;
        }

        out.open(LEETCODE_PROJECT_CMAKE_FILE, std::ios_base::app);
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
                t.replace(t.find("[comp]"), 6, lc_csv.competition_name);
            }

            while (t.find("[prob]") != std::string::npos)
            {
                t.replace(t.find("[prob]"), 6, lc_csv.problem_number);
            }

            out << t << "\n";
        }

        in.close();
        out.close();
    }
}

// IO
static void openLeetCodeProblemIOFiles(std::string problem_name)
{
    rft_leetcode_problem lc_prob = getPGLeetCodeProblem(problem_name);

    std::filesystem::path input_filename = std::filesystem::path(lc_prob.folder_path) / std::filesystem::path(lc_prob.problem_number + "_Input.txt");
    std::filesystem::path output_filename = std::filesystem::path(lc_prob.folder_path) / std::filesystem::path(lc_prob.problem_number + "_Output.txt");

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
