#ifndef __FIR_TARGETS_SYMBOL_H__
#define __FIR_TARGETS_SYMBOL_H__

#include <string>
#include <memory>
#include <cdk/types/basic_type.h>

namespace fir {

  class symbol {
    std::shared_ptr<cdk::basic_type> _type; // type (type id + type size)
    std::string _name;
    long _value; // hack! 
    bool _function;
    std::vector<std::shared_ptr<cdk::basic_type>> _argument_types;
    int _qualifier;
    int _offset = 0; // 0 (zero) means global variable/function

  public:
    symbol(std::shared_ptr<cdk::basic_type> type, const std::string &name, long value, bool function = false, int qualifier = 0) :
        _type(type), _name(name), _value(value), _function(function), _qualifier(qualifier) {
    }

    virtual ~symbol() {
      // EMPTY
    }

    std::shared_ptr<cdk::basic_type> type() const {
      return _type;
    }
    bool is_typed(cdk::typename_type name) const {
      return _type->name() == name;
    }
    void set_type(std::shared_ptr<cdk::basic_type> t) {
      _type = t;
    }
    const std::string &name() const {
      return _name;
    }
    long value() const {
      return _value;
    }
    long value(long v) {
      return _value = v;
    }
    bool isFunction() {
      return _function;
    }
    void set_argument_types(const std::vector<std::shared_ptr<cdk::basic_type>> &types) {
      _argument_types = types;
    }
    size_t number_of_arguments() const {
      return _argument_types.size();
    }

    size_t argument_size(size_t ax) const {
      return _argument_types[ax]->size();
    }
    std::shared_ptr<cdk::basic_type> argument_type(size_t ax) const {
      return _argument_types[ax];
    }
    bool argument_is_typed(size_t ax, cdk::typename_type name) const {
      return _argument_types[ax]->name() == name;
    }

    int offset() const {
      return _offset;
    }
    void set_offset(int offset) {
      _offset = offset;
    }
    bool global() const {
      return _offset == 0;
    }
  };

} // fir

#endif
