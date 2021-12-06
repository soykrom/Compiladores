#ifndef __FIR_AST_ITERATE_NODE_H__
#define __FIR_AST_ITERATE_NODE_H__

#include <cdk/ast/expression_node.h>

namespace fir {

  /**
   * Class for describing if-then-else nodes.
   */
  class iteratenode: public cdk::basic_node {
    cdk::expression_node *_condition;
    cdk::expression_node *_vetor;
	  int _count;
	  std::string _identifier;

  public:
    inline iterate_node(int lineno, cdk::expression_node *condition, cdk::expression_node *vetor, int count, const std::string &identifier) :
        cdk::basic_node(lineno), _condition(condition), _vetor(vetor), _count(count), _identifier(identifier) {
    }

  public:
    inline cdk::expression_node *condition() {
      return _condition;
    }
    inline cdk::expression_node *vetor() {
      return _vetor;
    }
    inline int *count() {
      return _int;
    }
	const std::string& identifier() {
      return _identifier;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_iterate_node(this, level);
    }

  };

} // fir

#endif
