#pragma once
#include "rft_global_cpp.hh"

static const std::filesystem::path ACTIVE_PROJECT_BUILD_PATH = std::filesystem::current_path();
static const std::filesystem::path ACTIVE_PROJECT_PATH = ACTIVE_PROJECT_BUILD_PATH.parent_path().parent_path().parent_path();
static const std::filesystem::path PROBLEMS_DIRECTORY = "Problems";
static const std::filesystem::path TEMPLATES_DIRECTORY = "Templates";



