#include <iostream>
#include "SaneQLLexer2.hpp" // Include your SaneQLLexer header file here

int main() {
    using namespace saneql;

    std::string input_query = "filter(r table, condition expression) join(left table, right table, on expression, type symbol := inner) as(r table, name symbol) map(r table, expressions list expression) project(r table, expressions list expression) projectout(r table, remove list symbol) group(r table, by list expression, aggs list expression, type symbol := group, sets list list symbol := {}) order(r table, by list expression) union(left table, right table) unionall(left table, right table) intersect(left table, right table) except(left table, right table) distinct(r table) window(r table, expressions list expression, partitionby list expression := {}, orderby list expression := {}, framebegin expression := unbounded(), frameend expression := currentrow(), frametype symbol := values) iterate(base table, recursion expression, increment symbol := iterate)";

    try {
        SaneQLLexer lexer(input_query);

        SaneQLLexer::TokenInfo tokenInfo;
        SaneQLLexer::Token token;

        std::string sql_query;

        // Iterate through the tokens in the input query
        do {
            token = lexer.next(tokenInfo);
            switch (token) {
                case SaneQLLexer::Token::Filter:
                    // Convert to SQL filter query
                    sql_query += "SELECT * FROM table WHERE condition;";
                    break;
                case SaneQLLexer::Token::Join:
                    // Convert to SQL join query
                    sql_query += "SELECT * FROM left_table INNER JOIN right_table ON expression;";
                    break;
                // Add cases for other SaneQL tokens and their corresponding SQL queries
                default:
                    // Handle other tokens if needed
                    break;
            }
        } while (token != SaneQLLexer::Token::Eof);

        std::cout << "SQL Query: " << sql_query << std::endl;

    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; // Return error code
    }

    return 0; // Return success
}
