//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/planner/operator/logical_set.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/common/enums/set_scope.hpp"
#include "duckdb/parser/parsed_data/copy_info.hpp"
#include "duckdb/planner/logical_operator.hpp"
#include "duckdb/function/copy_function.hpp"

namespace duckdb {

class LogicalSet : public LogicalOperator {
public:
	LogicalSet(std::string name_p, Value value_p, SetScope scope_p)
	    : LogicalOperator(LogicalOperatorType::LOGICAL_SET), name(name_p), value(value_p), scope(scope_p) {
	}

	std::string name;
	Value value;
	SetScope scope;

protected:
	void ResolveTypes() override {
		types.push_back(LogicalType::BOOLEAN);
	}
};

} // namespace duckdb
