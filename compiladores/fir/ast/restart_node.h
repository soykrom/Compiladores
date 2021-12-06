#ifndef __FIR_AST_RESTART_NODE_H
#define __FIR_AST_RESTART_NODE_H

#include <cdk/ast/basic_node.h>

namespace fir {

	class restart_node: public cdk::basic_node {
		int _level;

	public:
		restart_node(int linemo, int level = 1):
			cdk::basic_node(linemo), _level(level) {

		}

	public:
		inline int level() {
			return _level;
		}

		void accept(basic_ast_visitor *sp, int level) {
			sp->do_restart_node(this, level);
		}
	};

} // fir

#endif