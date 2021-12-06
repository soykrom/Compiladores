#ifndef __FIR_AST_RETURN_NODE_H__
#define __FIR_AST_RETURN_NODE_H__

#include <cdk/ast/basic_node.h>
#include <cdk/ast/expression_node.h>

namespace fir {

	class return_node: public cdk::basic_node {
	
	public:
		return_node(int linemo):
			cdk::basic_node(linemo) {

		}

	public:
		void accept(basic_ast_visitor *sp, int level) {
			sp->do_return_node(this, level);
		}
	};
}

#endif