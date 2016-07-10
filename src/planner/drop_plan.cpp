//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// drop_plan.cpp
//
// Identification: src/planner/drop_plan.cpp
//
// Copyright (c) 2015-16, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//


#include "planner/drop_plan.h"

#include "storage/data_table.h"
#include "catalog/bootstrapper.h"
#include "parser/drop_parse.h"
#include "parser/statement_drop.h"

namespace peloton {
namespace planner {

DropPlan::DropPlan(storage::DataTable *table) {
  catalog::Bootstrapper::bootstrap();
  catalog::Bootstrapper::global_catalog->CreateDatabase(DEFAULT_DB_NAME);
  target_table_ = table;
  missing = false;
}

DropPlan::DropPlan(std::string name) {
  catalog::Bootstrapper::bootstrap();
  catalog::Bootstrapper::global_catalog->CreateDatabase(DEFAULT_DB_NAME);
  table_name = name;
  target_table_ = catalog::Bootstrapper::global_catalog->GetTableFromDatabase(DEFAULT_DB_NAME, table_name);
  missing = false;
}

DropPlan::DropPlan(parser::DropParse *parse_tree) {
  catalog::Bootstrapper::bootstrap();
  catalog::Bootstrapper::global_catalog->CreateDatabase(DEFAULT_DB_NAME);
  table_name = parse_tree->GetEntityName();
  target_table_ = catalog::Bootstrapper::global_catalog->GetTableFromDatabase(DEFAULT_DB_NAME, table_name);
  missing = parse_tree->IsMissing();
}

DropPlan::DropPlan(parser::DropStatement *parse_tree) {
  catalog::Bootstrapper::bootstrap();
  catalog::Bootstrapper::global_catalog->CreateDatabase(DEFAULT_DB_NAME);
  table_name = parse_tree->name;
  target_table_ = catalog::Bootstrapper::global_catalog->GetTableFromDatabase(DEFAULT_DB_NAME, table_name);
  // Set it up for the moment , cannot seem to find it in DropStatement
  missing = false;
}

}  // namespace planner
}  // namespace peloton
