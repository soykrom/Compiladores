#include <string>
#include "targets/type_checker.h"
#include "targets/postfix_writer.h"
#include "ast/all.h"  // automatically generated
#include <cdk/types/primitive_type.h>

#include "fir_parser.tab.h"

#define ASSERT_UNSPEC { if (node->type() != nullptr && !node->is_typed(cdk::TYPE_UNSPEC)) return; }

//---------------------------------------------------------------------------

void fir::type_checker::do_sequence_node(cdk::sequence_node *const node, int lvl) {
    for (size_t i = 0; i < node->size(); i++)
    	node->node(i)->accept(this, lvl);
}

//---------------------------------------------------------------------------

void fir::type_checker::do_BooleanLogicalExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (!node->left()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary expression");
  }

  node->right()->accept(this, lvl + 2);
  if (!node->right()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary expression");
  }

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

//---------------------------------------------------------------------------

void fir::type_checker::do_nil_node(cdk::nil_node *const node, int lvl) {
  // EMPTY
}
void fir::type_checker::do_data_node(cdk::data_node *const node, int lvl) {
  // EMPTY
}
void fir::type_checker::do_double_node(cdk::double_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
}
void fir::type_checker::do_not_node(cdk::not_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (node->argument()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else if (node->argument()->is_typed(cdk::TYPE_UNSPEC)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->argument()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else {
    throw std::string("wrong type in unary logical expression");
  }
}
void fir::type_checker::do_and_node(cdk::and_node *const node, int lvl) {
  do_BooleanLogicalExpression(node, lvl);
}
void fir::type_checker::do_or_node(cdk::or_node *const node, int lvl) {
  do_BooleanLogicalExpression(node, lvl);
}

//---------------------------------------------------------------------------

void fir::type_checker::do_integer_node(cdk::integer_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void fir::type_checker::do_string_node(cdk::string_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
}

//---------------------------------------------------------------------------

void fir::type_checker::processUnaryExpression(cdk::unary_operation_node *const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
  if (!node->argument()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type in argument of unary expression");

  // in Simple, expressions are always int
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void fir::type_checker::do_IDExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  ////std::cout << "LeftType: " << node->left()->type()->name() << " LeftLabel: " << node->left()->label() << std::endl;
  ////std::cout << "RightType: " << node->right()->type()->name() << " RightLabel: " << node->right()->label() << std::endl;


  if (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_DOUBLE)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_DOUBLE)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else if (node->left()->is_typed(cdk::TYPE_UNSPEC) && node->right()->is_typed(cdk::TYPE_UNSPEC)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->left()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->right()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else {
    throw std::string("wrong types in binary expression");
  }
}

void fir::type_checker::do_PIDExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);


  ////std::cout << "LeftType: " << node->left()->type()->name() << " LeftLabel: " << node->left()->label() << std::endl;
  ////std::cout << "RightType: " << node->right()->type()->name() << " RightLabel: " << node->right()->label() << std::endl;
  if (node->left()->is_typed(cdk::TYPE_DOUBLE)) {
    //std::cout << "LeftType: DOUBLE"  << std::endl;
  } else if (node->left()->is_typed(cdk::TYPE_INT)) {
    //std::cout << "LeftType: INT"  << std::endl;
  } else if (node->left()->is_typed(cdk::TYPE_POINTER)) {
    //std::cout << "LeftType: POINTER"  << std::endl;
  } else if (node->left()->is_typed(cdk::TYPE_UNSPEC) && node->right()->is_typed(cdk::TYPE_UNSPEC)) {
    //std::cout << "LeftType: UNSPEC"  << std::endl;
  }
  else {
    //std::cout << "LeftType: nao tem tipo"  << std::endl;
  }

  

  if (node->right()->is_typed(cdk::TYPE_DOUBLE)) {
    //std::cout << "RightType: DOUBLE"  << std::endl;
  } else if (node->right()->is_typed(cdk::TYPE_INT)) {
    //std::cout << "RightType: INT"  << std::endl;
  } else if (node->right()->is_typed(cdk::TYPE_POINTER)) {
    //std::cout << "RightType: POINTER"  << std::endl;
  } else if (node->right()->is_typed(cdk::TYPE_UNSPEC) && node->right()->is_typed(cdk::TYPE_UNSPEC)) {
    //std::cout << "RightType: UNSPEC"  << std::endl;
  }


  if (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_DOUBLE)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_DOUBLE)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_POINTER) && node->right()->is_typed(cdk::TYPE_INT)) {
    node->type(node->left()->type());
  } else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_POINTER)) {
    node->type(node->right()->type());
  } else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else if (node->left()->is_typed(cdk::TYPE_UNSPEC) && node->right()->is_typed(cdk::TYPE_UNSPEC)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->left()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->right()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else {
    throw std::string("wrong types in binary expression");
  }

}

void fir::type_checker::do_IntOnlyExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (!node->left()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary operator (left)");
  }

  node->right()->accept(this, lvl + 2);
  if (!node->right()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary operator (right)");
  }

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void fir::type_checker::do_neg_node(cdk::neg_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl);
  if (node->argument()->is_typed(cdk::TYPE_INT)) {
    node->type(node->argument()->type());
  } else {
    throw std::string("integer or vector expressions expected");
  }
}

//---------------------------------------------------------------------------

void fir::type_checker::processBinaryExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (!node->left()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary operator (left)");
  }

  node->right()->accept(this, lvl + 2);
  if (!node->right()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary operator (right)");
  }

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void fir::type_checker::do_ScalarLogicalExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (!node->left()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary logical expression (left)");
  }

  node->right()->accept(this, lvl + 2);
  if (!node->right()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary logical expression (right)");
  }

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void fir::type_checker::do_GeneralLogicalExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  if (node->left()->type() != node->right()->type()) {
    throw std::string("same type expected on both sides of equality operator");
  }
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void fir::type_checker::do_add_node(cdk::add_node *const node, int lvl) {
  do_PIDExpression(node, lvl);
}
void fir::type_checker::do_sub_node(cdk::sub_node *const node, int lvl) {
  do_PIDExpression(node, lvl);
}
void fir::type_checker::do_mul_node(cdk::mul_node *const node, int lvl) {
  do_IDExpression(node, lvl);
}
void fir::type_checker::do_div_node(cdk::div_node *const node, int lvl) {
  do_IDExpression(node, lvl);
}
void fir::type_checker::do_mod_node(cdk::mod_node *const node, int lvl) {
  do_IntOnlyExpression(node, lvl);
}
void fir::type_checker::do_lt_node(cdk::lt_node *const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void fir::type_checker::do_le_node(cdk::le_node *const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void fir::type_checker::do_ge_node(cdk::ge_node *const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void fir::type_checker::do_gt_node(cdk::gt_node *const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void fir::type_checker::do_ne_node(cdk::ne_node *const node, int lvl) {
  do_GeneralLogicalExpression(node, lvl);
}
void fir::type_checker::do_eq_node(cdk::eq_node *const node, int lvl) {
  do_GeneralLogicalExpression(node, lvl);
}

//---------------------------------------------------------------------------

void fir::type_checker::do_variable_node(cdk::variable_node *const node, int lvl) {
  ASSERT_UNSPEC;
    //std::cout << "variable name: " << node->name() << std::endl;

  const std::string &id = node->name();
  std::shared_ptr<fir::symbol> symbol = _symtab.find(id);

  if (symbol != nullptr) {
    node->type(symbol->type());
  } else {
    throw id;
  }
}

void fir::type_checker::do_rvalue_node(cdk::rvalue_node *const node, int lvl) {
  ASSERT_UNSPEC;
  try {
    node->lvalue()->accept(this, lvl);
    node->type(node->lvalue()->type());
  } catch (const std::string &id) {
    throw "undeclared variable '" + id + "'";
  }
}

void fir::type_checker::do_assignment_node(cdk::assignment_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->lvalue()->accept(this, lvl + 4);
  node->rvalue()->accept(this, lvl + 4);

  if (node->lvalue()->is_typed(cdk::TYPE_INT)) {

    if (node->rvalue()->is_typed(cdk::TYPE_INT)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
      node->rvalue()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    } else {
      throw std::string("wrong assignment to integer");
    }
  } else if (node->lvalue()->is_typed(cdk::TYPE_POINTER)) {

    //TODO: check pointer level

    if (node->rvalue()->is_typed(cdk::TYPE_POINTER)) {
      node->type(node->rvalue()->type());
    } else if (node->rvalue()->is_typed(cdk::TYPE_INT)) {
      //TODO: check that the integer is a literal and that it is zero
      node->type(cdk::primitive_type::create(4, cdk::TYPE_POINTER));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_ERROR));
      node->rvalue()->type(cdk::primitive_type::create(4, cdk::TYPE_ERROR));
    } else {
      throw std::string("wrong assignment to pointer");
    }

  } else if (node->lvalue()->is_typed(cdk::TYPE_DOUBLE)) {

    if (node->rvalue()->is_typed(cdk::TYPE_DOUBLE) || node->rvalue()->is_typed(cdk::TYPE_INT)) {
      node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
      node->rvalue()->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
    } else {
      throw std::string("wrong assignment to real");
    }

  } else if (node->lvalue()->is_typed(cdk::TYPE_STRING)) {

    if (node->rvalue()->is_typed(cdk::TYPE_STRING)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
      node->rvalue()->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
    } else {
      throw std::string("wrong assignment to string");
    }

  } else {
    //throw std::string("wrong types in assignment");
  }
}

//---------------------------------------------------------------------------

void fir::type_checker::do_evaluation_node(fir::evaluation_node *const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

void fir::type_checker::do_print_node(fir::print_node *const node, int lvl) {
  node->arguments()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void fir::type_checker::do_read_node(fir::read_node *const node, int lvl) {
  // EMPTY!
}

//---------------------------------------------------------------------------

void fir::type_checker::do_while_node(fir::while_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}

void fir::type_checker::do_iterate_node(fir::iterate_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);

  node->vetor()->accept(this, lvl + 4); //60%

  const std::string &id = node->identifier();
  auto symbol = _symtab.find(node->identifier());
  if (symbol == nullptr) throw std::string("symbol '" + id + "' is undeclared.");
  if (!symbol->isFunction()) throw std::string("symbol '" + id + "' is not a function.");
}

//---------------------------------------------------------------------------

void fir::type_checker::do_if_node(fir::if_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}

void fir::type_checker::do_if_else_node(fir::if_else_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}

//---------------------------------------------------------------------------

void fir::type_checker::do_block_node(fir::block_node *const node, int lvl) {
  // EMPTY!
}
void fir::type_checker::do_leave_node(fir::leave_node *const node, int lvl) {
  // EMPTY!
}
void fir::type_checker::do_restart_node(fir::restart_node *const node, int lvl) {
  // EMPTY!
}
void fir::type_checker::do_return_node(fir::return_node *const node, int lvl) {
  // EMPTY!
}

void fir::type_checker::do_sizeof_node(fir::sizeof_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->expression()->accept(this, lvl + 2);
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void fir::type_checker::do_nullptr_node(fir::nullptr_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::reference_type::create(4, nullptr));
}

void fir::type_checker::do_function_call_node(fir::function_call_node *const node, int lvl) {
  ASSERT_UNSPEC;

  //std::cout << "Function Call Node: " << node->identifier() << "\n";

  const std::string &id = node->identifier();
  auto symbol = _symtab.find(node->identifier());
  if (symbol == nullptr) throw std::string("symbol '" + id + "' is undeclared.");
  if (!symbol->isFunction()) throw std::string("symbol '" + id + "' is not a function.");


  node->type(symbol->type());
  

  if (node->arguments()->size() == symbol->number_of_arguments()) {
    node->arguments()->accept(this, lvl + 4);
    for (size_t ax = 0; ax < node->arguments()->size(); ax++) {
      if (node->argument(ax)->type() == symbol->argument_type(ax)) continue;
      if (symbol->argument_is_typed(ax, cdk::TYPE_DOUBLE) && node->argument(ax)->is_typed(cdk::TYPE_INT)) continue;
      throw std::string("type mismatch for argument " + std::to_string(ax + 1) + " of '" + id + "'.");
    }
  } else {
    throw std::string(
        "number of arguments in call (" + std::to_string(node->arguments()->size()) + ") must match declaration ("
            + std::to_string(symbol->number_of_arguments()) + ").");
  }
  //std::cout << "ola\n";
  node->type(symbol->type());
}

void fir::type_checker::do_function_decl_node(fir::function_decl_node *const node, int lvl) {
  std::string id;

  // "fix" naming issues...
  if (node->identifier() == "fir")
    id = "_main";
  else if (node->identifier() == "_main")
    id = "._main";
  else
    id =node->identifier();

  // remember symbol so that args know
  auto function = std::make_shared<fir::symbol>(node->type(), id, 0, true,  node->qualifier());

  std::vector < std::shared_ptr < cdk::basic_type >> argtypes;
  for (size_t ax = 0; ax < node->arguments()->size(); ax++)
    argtypes.push_back(node->argument(ax)->type());
  function->set_argument_types(argtypes);

  std::shared_ptr<fir::symbol> previous = _symtab.find(function->name());
  if (previous && function->number_of_arguments() == previous->number_of_arguments()) {
    size_t ax;
    for (ax = 0; ax < function->number_of_arguments(); ax++) {
      if ((previous->argument_type(ax) != function->argument_type(ax)))
        break;
    }
    if(ax == function->number_of_arguments() -1)
      throw std::string("conflicting declaration for '" + function->name() + "'");
  }
    
  _symtab.insert(function->name(), function);
  _parent->set_new_symbol(function);
  
}

void fir::type_checker::do_function_def_node(fir::function_def_node *const node, int lvl) {
  
  std::string id;
  if (node->identifier() == "fir")
    id = "_main";
  else if (node->identifier() == "_main")
    id = "._main";
  else
    id = node->identifier();


  auto function = std::make_shared<fir::symbol>(node->type(),  id, 0, true, node->qualifier());

  std::vector < std::shared_ptr < cdk::basic_type >> argtypes;
  for (size_t ax = 0; ax < node->arguments()->size(); ax++)
    argtypes.push_back(node->argument(ax)->type());
  function->set_argument_types(argtypes);

  std::shared_ptr<fir::symbol> previous = _symtab.find(function->name());
  
  if (previous && function->number_of_arguments() == previous->number_of_arguments()) {
    size_t ax;
    for (ax = 0; ax < function->number_of_arguments(); ax++) {
      if ((previous->argument_type(ax) != function->argument_type(ax)))
        break;
    }
    
    if(ax == function->number_of_arguments() -1)
      throw std::string("conflicting declaration for '" + function->name() + "'");
    else {
      _symtab.replace(function->name(), function);
      _parent->set_new_symbol(function);
    }
  }
  else {
    _symtab.insert(function->name(), function);
    _parent->set_new_symbol(function);
  }
   


  if (node->rtval()) {
    if (function->type() != nullptr && function->is_typed(cdk::TYPE_VOID)) throw std::string(
        "initializer specified for void function.");

    node->rtval()->accept(this, lvl + 2);

    // function is auto: copy type of first return expression
    if (function->type() == nullptr) {
      if(node->rtval())
        function->set_type(node->rtval()->type());
      else
        function->set_type(cdk::primitive_type::create(0, cdk::TYPE_VOID));
      return; // simply set the type
    }



    if (function->is_typed(cdk::TYPE_INT)) {
      if (!node->rtval()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type for initializer (integer expected).");
    } else if (function->is_typed(cdk::TYPE_DOUBLE)) {
      if (!node->rtval()->is_typed(cdk::TYPE_INT) && !node->rtval()->is_typed(cdk::TYPE_DOUBLE)) {
        throw std::string("wrong type for initializer (integer or double expected).");
      }
    } else if (function->is_typed(cdk::TYPE_STRING)) {
      if (!node->rtval()->is_typed(cdk::TYPE_STRING)) {
        throw std::string("wrong type for initializer (string expected).");
      }
    } else if (function->is_typed(cdk::TYPE_POINTER)) {
      //DAVID: FIXME: trouble!!!
      int ft = 0, rt = 0;
      auto ftype = function->type();
      while (ftype->name() == cdk::TYPE_POINTER) {
        ft++;
        ftype = cdk::reference_type::cast(ftype)->referenced();
      }
      auto rtype = node->rtval()->type();
      while (rtype != nullptr && rtype->name() == cdk::TYPE_POINTER) {
        rt++;
        rtype = cdk::reference_type::cast(rtype)->referenced();
      }

      bool compatible = (ft == rt) && (rtype == nullptr || (rtype != nullptr && ftype->name() == rtype->name()));
      if (!compatible) throw std::string("wrong type for return expression (pointer expected).");

    } else {
      throw std::string("unknown type for initializer.");
    }
  }
}

void fir::type_checker::do_address_of_node(fir::address_of_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->lvalue()->accept(this, lvl + 2);
  node->type(cdk::reference_type::create(4, node->lvalue()->type()));
}

void fir::type_checker::do_variable_declaration_node(fir::variable_declaration_node *const node, int lvl) {
  if (node->initializer() != nullptr) {
    node->initializer()->accept(this, lvl + 2);

    if (node->is_typed(cdk::TYPE_INT)) {
      if (!node->initializer()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type for initializer (integer expected).");
    } else if (node->is_typed(cdk::TYPE_DOUBLE)) {
      if (!node->initializer()->is_typed(cdk::TYPE_INT) && !node->initializer()->is_typed(cdk::TYPE_DOUBLE)) {
        throw std::string("wrong type for initializer (integer or double expected).");
      }
    } else if (node->is_typed(cdk::TYPE_STRING)) {
      if (!node->initializer()->is_typed(cdk::TYPE_STRING)) {
        throw std::string("wrong type for initializer (string expected).");
      }
    } else if (node->is_typed(cdk::TYPE_POINTER)) {
      //DAVID: FIXME: trouble!!!
      if (!node->initializer()->is_typed(cdk::TYPE_POINTER)) {
        auto in = (cdk::literal_node<int>*)node->initializer();
        if (in == nullptr || in->value() != 0) throw std::string("wrong type for initializer (pointer expected).");
      }
    } else {
      throw std::string("unknown type for initializer.");
    }
  }

  //////std::cout << "variable identifier: " << node->identifier() << std::endl;
  const std::string &id = node->identifier();

  auto symbol = std::make_shared<fir::symbol>(node->type(), id, 0, false, node->qualifier());
  if (_symtab.insert(id, symbol)) {
    _parent->set_new_symbol(symbol);  // advise parent that a symbol has been inserted
  } else {
    throw std::string("variable '" + id + "' redeclared");
  }

}


void fir::type_checker::do_alloc_node(fir::alloc_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (!node->argument()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in allocation expression");
  }
  //DAVID TODO FIXME
  auto mytype = cdk::reference_type::create(4, cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  node->type(mytype);
}

void fir::type_checker::do_index_node(fir::index_node *const node, int lvl) {
  ASSERT_UNSPEC;

  std::shared_ptr < cdk::reference_type > btype;

  node->base()->accept(this, lvl + 2);
  btype = cdk::reference_type::cast(node->base()->type());
  if (!node->base()->is_typed(cdk::TYPE_POINTER)) throw std::string("pointer expression expected in index left-value");

  node->index()->accept(this, lvl + 2);
  if (!node->index()->is_typed(cdk::TYPE_INT)) throw std::string("integer expression expected in left-value index");

  node->type(btype->referenced());
}

void fir::type_checker::do_identity_node(fir::identity_node *const node, int lvl) {
  processUnaryExpression(node, lvl);
}