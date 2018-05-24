#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <string>
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <functional>
#include <sstream>
#include <deque>
#include <cassert>
#include <fstream>
#include <boost/scope_exit.hpp>
#include <boost/optional.hpp>
#include <boost/filesystem.hpp>
#include <boost/optional.hpp>
#include <boost/none.hpp>
#include <boost/range/algorithm/find_if.hpp>
#include <boost/algorithm/string/replace.hpp>
#include "CDocumentItem.h"
#include "ICommand.h"

using Path = boost::filesystem::path;
using DocumentItemPtr = std::shared_ptr<CDocumentItem>;
using ConstDocumentItemPtr = const std::shared_ptr<CDocumentItem> &;
using ICommandPtr = std::unique_ptr<ICommand>;
