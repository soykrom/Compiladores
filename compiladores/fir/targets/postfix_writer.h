#ifndef __FIR_TARGETS_POSTFIX_WRITER_H__
#define __FIR_TARGETS_POSTFIX_WRITER_H__

#include "targets/basic_ast_visitor.h"

#include <set>
#include <sstream>
#include <cdk/emitters/basic_postfix_emitter.h>
#include <stack>

namespace fir {

  //!
  //! Traverse syntax tree and generate the corresponding assembly code.
  //!
  class postfix_writer: public basic_ast_visitor {
    cdk::symbol_table<fir::symbol> &_symtab;
    cdk::basic_postfix_emitter &_pf;
    int _lbl;
    std::stack<int> _whileIni, _whileEnd; // for leave/restart
    std::set<std::string> _functionsToDeclare;
    std::shared_ptr<fir::symbol> _function; // for keeping track of the current function and its arguments
    int _offset = 0; // current framepointer offset (0 means no vars defined)
    cdk::typename_type _lvalueType;

    // remember function name for resolving '@'
    std::string _currentFunctionName;
    std::string _currentBodyRetLabel; // where to jump when a return occurs of an exclusive section ends
    std::string _epilogueLabel;
    int _functionStep;

    bool _errors, _inFunction = false, _inFunctionName = false, _inFunctionArgs = false, _inFunctionBody = false;

  public:
    postfix_writer(std::shared_ptr<cdk::compiler> compiler, cdk::symbol_table<fir::symbol> &symtab,
                   cdk::basic_postfix_emitter &pf) :
        basic_ast_visitor(compiler), _symtab(symtab), _pf(pf), _lbl(0) {
    }

  public:
    ~postfix_writer() {
      os().flush();
    }

  private:
    /** Method used to generate sequential labels. */
    inline std::string mklbl(int lbl) {
      std::ostringstream oss;
      if (lbl < 0)
        oss << ".L" << -lbl;
      else
        oss << "_L" << lbl;
      return oss.str();
    }

    void error(int lineno, std::string s) {
      std::cerr << "error: " << lineno << ": " << s << std::endl;
    }

  public:
  // do not edit these lines
#define __IN_VISITOR_HEADER__
#include "ast/visitor_decls.h"       // automatically generated
#undef __IN_VISITOR_HEADER__
  // do not edit these lines: end

  };

} // fir

#endif
