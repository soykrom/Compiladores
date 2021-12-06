#ifndef __FIR_AST_FUNCTION_DEFINITION_NODE_H__
#define __FIR_AST_FUNCTION_DEFINITION_NODE_H__

#include <string>
#include <cdk/ast/typed_node.h>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include "ast/block_node.h"

namespace fir {
  class function_def_node: public cdk::typed_node {
    int _qualifier;
    std::string _identifier;
    cdk::sequence_node *_arguments;
    cdk::expression_node *_rtval;
    fir::block_node *_block = nullptr;
    fir::block_node *_prologue = nullptr;
    fir::block_node *_epilogue = nullptr;

  public:
    /*function_def_node(int lineno, int qualifier, const std::string &identifier, cdk::sequence_node *arguments, fir::block_node *block = nullptr,
                        cdk::sequence_node *prologue = nullptr, cdk::sequence_node *epilogue = nullptr) :
        cdk::typed_node(lineno), _qualifier(qualifier), _identifier(identifier), _arguments(arguments), _block(block), _prologue(prologue), _epilogue(epilogue) {
      type(cdk::primitive_type::create(0, cdk::TYPE_VOID));
    }*/

    function_def_node(int lineno, int qualifier, std::shared_ptr<cdk::basic_type> funType, const std::string &identifier, cdk::sequence_node *arguments,
                            cdk::expression_node *rtval = nullptr, fir::block_node *block = nullptr, fir::block_node *prologue = nullptr, fir::block_node *epilogue = nullptr ) :
        cdk::typed_node(lineno), _qualifier(qualifier), _identifier(identifier), _arguments(arguments), _rtval(rtval), _block(block), _prologue(prologue), _epilogue(epilogue) {
      type(funType);
    }

  public:
    int qualifier() {
      return _qualifier;
    }
    const std::string& identifier() const {
      return _identifier;
    }
    cdk::sequence_node* arguments() {
      return _arguments;
    }
    cdk::typed_node* argument(size_t ax) {
      return dynamic_cast<cdk::typed_node*>(_arguments->node(ax));
    }
    cdk::expression_node* rtval() {
      return _rtval;
    }
    fir::block_node* block() {
      return _block;
    }
    fir::block_node* prologue() {
      return _prologue;
    }
    fir::block_node* epilogue() {
      return _epilogue;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_def_node(this, level);
    }

  };

} // fir

#endif
