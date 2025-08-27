#pragma once
#include "rft_global_cpp.hh"
#include "rft_io.hh"
#include "rft_paths.hh"
#include "rft_postgre_sql.hh"
#include "rft_string.hh"
#include "rft_time.hh"
#include "rft_unit_test.hh"

struct rft_codingame_csv
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

struct rft_codingame_competition
{
    long id;
    std::string competition_name;
    std::string timestamp;
    int rank;
    int rating;
    std::string folder_path;
};

struct rft_codingame_problem
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

struct rft_codingame_solution
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

static const std::filesystem::path CODINGAME_PROJECT_PATH = ACTIVE_PROJECT_PATH / "Rftim3CodinGame";
static const std::filesystem::path CODINGAME_PROJECT_CMAKE_FILE = ACTIVE_PROJECT_PATH / "CMakeLists.txt";
static const std::filesystem::path CODINGAME_PROBLEM_NAMES_FILE = CODINGAME_PROJECT_PATH / TEMPLATES_DIRECTORY / "CodinGameProblemNames.csv";
static const std::filesystem::path CODINGAME_PROJECT_PROBLEMS_DIRECTORY_PATH = CODINGAME_PROJECT_PATH / PROBLEMS_DIRECTORY;
static const std::filesystem::path CODINGAME_PROBLEM_MAIN_HEADER_FILE_TEMPLATE = CODINGAME_PROJECT_PATH / TEMPLATES_DIRECTORY / "CodinGameMainHeaderFileTemplate.txt";
static const std::filesystem::path CODINGAME_PROBLEM_MAIN_SOURCE_FILE_TEMPLATE = CODINGAME_PROJECT_PATH / TEMPLATES_DIRECTORY / "CodinGameMainSourceFileTemplate.txt";
static const std::filesystem::path CODINGAME_PROBLEM_SOLUTION_FILE_TEMPLATE = CODINGAME_PROJECT_PATH / TEMPLATES_DIRECTORY / "CodinGameSolutionFileTemplate.txt";
static const std::filesystem::path CODINGAME_PROBLEM_CMAKE_TEMPLATE_FILE = CODINGAME_PROJECT_PATH / TEMPLATES_DIRECTORY / "CodinGameCMakeListsTemplate.txt";
static const std::filesystem::path CODINGAME_PROJECT_CMAKE_TEMPLATE_FILE = CODINGAME_PROJECT_PATH / TEMPLATES_DIRECTORY / "CodinGameProjectCMakeListsTemplate.txt";
static const std::filesystem::path CODINGAME_PROBLEMS_DIRECTORY_PATH = ACTIVE_PROJECT_PATH.parent_path().parent_path() / "Rftim3CodinGame" / PROBLEMS_DIRECTORY;

// CSV
static void printCodinGameCSV(rft_codingame_csv cg_csv)
{
    std::cout << cg_csv.competition_name << "\n";
    std::cout << cg_csv.rank << "\n";
    std::cout << cg_csv.rating << "\n";
    std::cout << cg_csv.problem_number << "\n";
    std::cout << cg_csv.problem_title << "\n";
    std::cout << cg_csv.problem_description << "\n";
    std::cout << cg_csv.problem_input << "\n";
    std::cout << cg_csv.difficulty << "\n";
    for (int i = 0; i < cg_csv.algorithms.size(); i++)
    {
        if (i == cg_csv.algorithms.size() - 1)
            std::cout << cg_csv.algorithms[i] << "\n";
        else
            std::cout << cg_csv.algorithms[i] << ", ";
    }
}

static void printAllCodinGameCSV(std::vector<rft_codingame_csv> cg_csv)
{
    for (auto &&i : cg_csv)
    {
        printCodinGameCSV(i);
    }
}

static std::vector<std::string> getAllRowsCSVCodinGameProblemNames()
{
    static std::vector<std::string> v = {};

    // open file read
    in.open(CODINGAME_PROBLEM_NAMES_FILE);
    if (!in.is_open())
    {
        std::cerr << "Error opening problem names file input: " << CODINGAME_PROBLEM_NAMES_FILE << std::endl;
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
    if (input.find("cg_") == std::string::npos)
    {
        std::string res = "";
        res += "cg_";

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

static std::vector<rft_codingame_csv> getCSVCodinGameProblemNames()
{
    std::vector<std::string> cg_csv_rows = getAllRowsCSVCodinGameProblemNames();
    std::vector<rft_codingame_csv> cg_problems = {};

    // store problems as objects
    if (cg_csv_rows.size() > 0)
    {
        for (auto &&i : cg_csv_rows)
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

            rft_codingame_csv cg_problem;
            cg_problem.competition_name = tokens[0].size() > 0 ? tokens[0] : "";
            cg_problem.problem_number = tokens[1].size() > 0 ? tokens[1] : "";
            cg_problem.problem_title = tokens[2].size() > 0 ? tokens[2] : "";
            cg_problem.difficulty = tokens[3].size() > 0 ? std::stoi(tokens[3]) : 0;
            cg_problem.algorithms = topics.size() > 0 ? topics : std::vector<std::string>();

            cg_problems.push_back(cg_problem);
        }
    }

    return cg_problems;
}

static void insertPGCodinGameTable(rft_codingame_csv rft_csv)
{
    std::string conn_str = getPGLeviathanConnectionString();

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "CALL PUBLIC.SP_CODINGAME_INSERT($1, $2, $3, $4, $5)";

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

static void insertPGCodinGameTable(std::vector<rft_codingame_csv> rft_csvs)
{
    std::string conn_str = getPGLeviathanConnectionString();

    try
    {
        for (auto &&rft_csv : rft_csvs)
        {
            pqxx::connection conn(conn_str);
            pqxx::work worker(conn);

            std::string sql = "CALL PUBLIC.SP_CODINGAME_INSERT($1, $2, $3, $4, $5)";

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
static void printCodinGameCompetition(rft_codingame_competition cg_comp)
{
    std::cout << "Id: " << cg_comp.id << "\n";
    std::cout << "Competition name: " << cg_comp.competition_name << "\n";
    std::cout << "Timestamp: " << cg_comp.timestamp << "\n";
    std::cout << "Rank: " << cg_comp.rank << "\n";
    std::cout << "Rating: " << cg_comp.rating << "\n";
    std::cout << "Folder path: " << cg_comp.folder_path << "\n";
}

static void printCodinGameCompetitions(std::vector<rft_codingame_competition> cg_comp)
{
    for (auto &&i : cg_comp)
    {
        printCodinGameCompetition(i);
    }
}

static void printCodinGameProblem(rft_codingame_problem cg_prob)
{
    std::cout << "Id: " << cg_prob.id << "\n";
    std::cout << "Competition id: " << cg_prob.competition_id << "\n";
    std::cout << "Problem number: " << cg_prob.problem_number << "\n";
    std::cout << "Problem title: " << cg_prob.problem_title << "\n";
    std::cout << "Problem description: " << cg_prob.problem_description << "\n";
    std::cout << "Problem input: " << cg_prob.problem_input << "\n";
    std::cout << "Difficulty: " << cg_prob.difficulty << "\n";
    std::cout << "Folder path: " << cg_prob.folder_path << "\n";
}

static void printCodinGameProblems(std::vector<rft_codingame_problem> cg_prob)
{
    for (auto &&i : cg_prob)
    {
        printCodinGameProblem(i);
    }
}

static void printCodinGameSolution(rft_codingame_solution cg_sol)
{
    std::cout << "Id: " << cg_sol.id << "\n";
    std::cout << "Problem id: " << cg_sol.problem_id << "\n";
    std::cout << "Solution name: " << cg_sol.solution_name << "\n";
    std::cout << "Test status: " << cg_sol.test_status << "\n";
    std::cout << "Runtime: " << cg_sol.runtime << "\n";
    std::cout << "Memory: " << cg_sol.memory << "\n";
    std::cout << "Algorithms: ";
    for (int i = 0; i < cg_sol.algorithms.size(); i++)
    {
        if (i == cg_sol.algorithms.size() - 1)
            std::cout << cg_sol.algorithms[i] << ";";
        else
            std::cout << cg_sol.algorithms[i] << ", ";
    }
    std::cout << "\n";
    std::cout << "File path: " << cg_sol.file_path << "\n";
}

static void printCodinGameSolutions(std::vector<rft_codingame_solution> cg_sol)
{
    for (auto &&i : cg_sol)
    {
        printCodinGameSolution(i);
    }
}

static void insertPGCodinGameCompetition(rft_codingame_competition cg_comp)
{
    std::string conn_str = getPGLeviathanConnectionString();

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "CALL PUBLIC.SP_CODINGAME_COMPETITION_INSERT($1, $2, $3, $4, $5)";

        worker.exec(sql, pqxx::params(cg_comp.competition_name,
                                      cg_comp.timestamp,
                                      cg_comp.rank,
                                      cg_comp.rating,
                                      cg_comp.folder_path));

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

static void insertPGCodinGameProblem(rft_codingame_problem cg_prob)
{
    std::string conn_str = getPGLeviathanConnectionString();

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "CALL PUBLIC.SP_CODINGAME_PROBLEM_INSERT($1, $2, $3, $4, $5, $6, $7)";

        worker.exec(sql, pqxx::params(cg_prob.competition_id,
                                      cg_prob.problem_number,
                                      cg_prob.problem_title,
                                      cg_prob.problem_description,
                                      cg_prob.problem_input,
                                      cg_prob.difficulty,
                                      cg_prob.folder_path));

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

static void insertPGCodinGameSolution(rft_codingame_solution cg_sol)
{
    std::string conn_str = getPGLeviathanConnectionString();

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "CALL PUBLIC.SP_CODINGAME_SOLUTION_INSERT($1, $2, $3, $4, $5, $6, $7)";

        worker.exec(sql, pqxx::params(cg_sol.problem_id,
                                      cg_sol.solution_name,
                                      cg_sol.test_status,
                                      cg_sol.runtime,
                                      cg_sol.memory,
                                      cg_sol.algorithms,
                                      cg_sol.file_path));

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

static rft_codingame_competition getPGCodinGameCompetition(std::string cg_comp)
{
    std::string conn_str = getPGLeviathanConnectionString();
    rft_codingame_competition rft_cg_comp;

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "SELECT * FROM FN_CODINGAME_COMPETITIONS_SELECT_BY_COMPETITION_NAME ($1);";
        pqxx::result res = worker.exec(sql, pqxx::params(cg_comp));

        if (res.size() > 0)
        {
            rft_cg_comp.id = res[0]["id"].as<long>();
            rft_cg_comp.competition_name = res[0]["competition_name"].as<std::string>();
            rft_cg_comp.timestamp = res[0]["timestamp"].as<std::string>();
            rft_cg_comp.rank = res[0]["rank"].as<int>();
            rft_cg_comp.rating = res[0]["rating"].as<int>();
            rft_cg_comp.folder_path = res[0]["folder_path"].as<std::string>();
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

    return rft_cg_comp;
}

static rft_codingame_problem getPGCodinGameProblem(std::string cg_prob)
{
    std::string conn_str = getPGLeviathanConnectionString();
    rft_codingame_problem rft_cg_prob;

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "SELECT * FROM FN_CODINGAME_PROBLEMS_SELECT_BY_PROBLEM_NUMBER ($1)";
        pqxx::result res = worker.exec(sql, pqxx::params(cg_prob));

        if (res.size() > 0)
        {
            rft_cg_prob.id = res[0]["id"].as<long>();
            rft_cg_prob.competition_id = res[0]["competition_id"].as<long>();
            rft_cg_prob.problem_number = res[0]["problem_number"].as<std::string>();
            rft_cg_prob.problem_title = res[0]["problem_title"].as<std::string>();
            rft_cg_prob.problem_description = res[0]["problem_description"].as<std::string>();
            rft_cg_prob.problem_input = res[0]["problem_input"].as<std::string>();
            rft_cg_prob.difficulty = res[0]["difficulty"].as<int>();
            rft_cg_prob.folder_path = res[0]["folder_path"].as<std::string>();
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

    return rft_cg_prob;
}

static rft_codingame_solution getPGCodinGameSolution(std::string cg_sol)
{
    std::string conn_str = getPGLeviathanConnectionString();
    rft_codingame_solution rft_cg_sol;

    try
    {
        pqxx::connection conn(conn_str);
        pqxx::work worker(conn);

        std::string sql = "SELECT * FROM FN_CODINGAME_SOLUTIONS_SELECT_BY_SOLUTION_NAME ($1)";
        pqxx::result res = worker.exec(sql, pqxx::params(cg_sol));

        if (res.size() > 0)
        {
            rft_cg_sol.id = res[0]["id"].as<long>();
            rft_cg_sol.problem_id = res[0]["problem_id"].as<long>();
            rft_cg_sol.solution_name = res[0]["solution_name"].as<std::string>();
            rft_cg_sol.test_status = res[0]["test_status"].as<bool>();
            rft_cg_sol.runtime = res[0]["runtime"].as<double>();
            rft_cg_sol.memory = res[0]["memory"].as<double>();
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
            rft_cg_sol.algorithms = algos;
            rft_cg_sol.file_path = res[0]["file_path"].as<std::string>();
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

    return rft_cg_sol;
}

static void insertPGCodinGameFullProblem(rft_codingame_csv cg_csv)
{
    rft_codingame_competition cg_comp = getPGCodinGameCompetition(cg_csv.competition_name);
    rft_codingame_problem cg_prob = getPGCodinGameProblem(cg_csv.problem_number);

    // create competition
    if (cg_comp.competition_name == "")
    {
        std::filesystem::path comp_dir = CODINGAME_PROJECT_PROBLEMS_DIRECTORY_PATH / cg_csv.competition_name;
        if (!std::filesystem::exists(comp_dir))
            std::filesystem::create_directory(comp_dir);

        cg_comp.competition_name = cg_csv.competition_name;
        cg_comp.timestamp = getCurrentTimestamp();
        cg_comp.rank = cg_csv.rank;
        cg_comp.rating = cg_csv.rating;
        cg_comp.folder_path = comp_dir.string();
        insertPGCodinGameCompetition(cg_comp);
        cg_comp = getPGCodinGameCompetition(cg_csv.competition_name);
    }

    // create problem
    if (cg_prob.problem_number == "")
    {
        cg_prob.competition_id = cg_comp.id;
        cg_prob.problem_number = cg_csv.problem_number;
        cg_prob.problem_title = cg_csv.problem_title;
        cg_prob.problem_description = cg_csv.problem_description;
        cg_prob.problem_input = cg_csv.problem_input;
        cg_prob.difficulty = cg_csv.difficulty;
        cg_prob.folder_path = (std::filesystem::path(cg_comp.folder_path) / cg_prob.problem_number).string();
        insertPGCodinGameProblem(cg_prob);
        cg_prob = getPGCodinGameProblem(cg_csv.problem_number);
    }

    // create problem directory
    std::filesystem::path prob_dir = std::filesystem::path(cg_comp.folder_path) / cg_csv.problem_number;
    if (!std::filesystem::exists(prob_dir))
        std::filesystem::create_directory(prob_dir);

    // create io files
    std::filesystem::path input_file = prob_dir / std::filesystem::path(cg_prob.problem_number + "_Input.txt");
    if (!std::filesystem::exists(input_file))
    {
        std::ofstream new_input_file;
        new_input_file.open(input_file, std::fstream::trunc);
        new_input_file << cg_prob.problem_input;
        new_input_file.close();
    }

    std::filesystem::path output_file = prob_dir / std::filesystem::path(cg_prob.problem_number + "_Output.txt");
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
        fp.open(CODINGAME_PROBLEM_MAIN_HEADER_FILE_TEMPLATE, std::ios::in);
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
            std::string cg_sol = cg_prob.problem_number + "_0";

            while (t.find("[sol]") != std::string::npos)
            {
                t.replace(t.find("[sol]"), 5, cg_sol);
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
        fp.open(CODINGAME_PROBLEM_MAIN_SOURCE_FILE_TEMPLATE, std::ios::in);
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
            std::string cg_sol = cg_csv.problem_number + "_0";

            while (t.find("[sol]") != std::string::npos)
            {
                t.replace(t.find("[sol]"), 5, cg_sol);
            }

            new_source_file << t << "\n";
        }

        new_source_file.close();
    }

    // create solution
    std::filesystem::path solution_filename = prob_dir / std::filesystem::path(cg_csv.problem_number + "_0.cc");
    if (!std::filesystem::exists(solution_filename))
    {
        std::fstream fp;
        fp.open(CODINGAME_PROBLEM_SOLUTION_FILE_TEMPLATE, std::ios::in);
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
            std::string cg_sol = cg_csv.problem_number + "_0";

            while (t.find("[sol]") != std::string::npos)
            {
                t.replace(t.find("[sol]"), 5, cg_sol);
            }

            new_solution_file << t << "\n";
        }

        new_solution_file.close();
    }

    if (getPGCodinGameSolution(cg_prob.problem_number + "_0.cc").solution_name == "")
    {
        rft_codingame_solution cg_sol;
        cg_sol.problem_id = cg_prob.id;
        cg_sol.solution_name = cg_csv.problem_number + "_0.cc";
        cg_sol.test_status = false;
        cg_sol.runtime = 0.0;
        cg_sol.memory = 0.0;
        cg_sol.algorithms = cg_csv.algorithms;
        cg_sol.file_path = (std::filesystem::path(cg_comp.folder_path) / cg_prob.problem_number / (cg_csv.problem_number + "_0.cc")).string();
        insertPGCodinGameSolution(cg_sol);
    }

    // create cmakelists
    std::filesystem::path cmake_filename = prob_dir / std::filesystem::path("CMakeLists.txt");
    if (!std::filesystem::exists(cmake_filename))
    {
        std::fstream fp;
        fp.open(CODINGAME_PROBLEM_CMAKE_TEMPLATE_FILE, std::ios::in);
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
            std::string cg_prob = cg_csv.problem_number;

            while (t.find("[prob]") != std::string::npos)
            {
                t.replace(t.find("[prob]"), 6, cg_prob);
            }

            new_cmake_file << t << "\n";
        }

        new_cmake_file.close();

        // link cmake
        in.open(CODINGAME_PROJECT_CMAKE_TEMPLATE_FILE);
        if (!in.is_open())
        {
            std::cerr << "Error opening project cmake file" << std::endl;
            return;
        }

        out.open(CODINGAME_PROJECT_CMAKE_FILE, std::ios_base::app);
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
                t.replace(t.find("[comp]"), 6, cg_csv.competition_name);
            }

            while (t.find("[prob]") != std::string::npos)
            {
                t.replace(t.find("[prob]"), 6, cg_csv.problem_number);
            }

            out << t << "\n";
        }

        in.close();
        out.close();
    }
}

// IO
static void openCodinGameProblemIOFiles(std::string problem_name)
{
    rft_codingame_problem cg_prob = getPGCodinGameProblem(problem_name);

    std::filesystem::path input_filename = std::filesystem::path(cg_prob.folder_path) / std::filesystem::path(cg_prob.problem_number + "_Input.txt");
    std::filesystem::path output_filename = std::filesystem::path(cg_prob.folder_path) / std::filesystem::path(cg_prob.problem_number + "_Output.txt");

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


