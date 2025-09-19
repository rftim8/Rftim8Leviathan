#pragma once
#include "rft_global_cpp.hh"
#include <pqxx/pqxx>

// Connect
static std::string getPGLeviathanConnectionString()
{
    char *host = nullptr, *port = nullptr, *dbname = nullptr, *user = nullptr, *password = nullptr;
    size_t len = 0;

    _dupenv_s(&host, &len, "PGHOST");
    _dupenv_s(&port, &len, "PGPORT");
    _dupenv_s(&dbname, &len, "PGLeviathanDB");
    _dupenv_s(&user, &len, "PGUSER");
    _dupenv_s(&password, &len, "PGPASSWORD");

    if (!host || !port || !dbname || !user || !password)
    {
        std::cerr << "Database credentials not set in environment variables.\n";
        if (host)
            free(host);

        if (port)
            free(port);

        if (dbname)
            free(dbname);

        if (user)
            free(user);

        if (password)
            free(password);

        return "";
    }

    std::string conn_str = "host=" + std::string(host) +
                           " port=" + std::string(port) +
                           " dbname=" + std::string(dbname) +
                           " user=" + std::string(user) +
                           " password=" + std::string(password);

    free(host);
    free(port);
    free(dbname);
    free(user);
    free(password);

    return conn_str;
}
