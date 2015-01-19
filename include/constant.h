/**
 *  Constant.h
 * 
 *  If you want to define global PHP constants, or class constants you can
 *  use this constant class for it. Wrap the constant you'd like to create
 *  in a Php::Constant object and add it to the extension or the class:
 * 
 *  extension.add(Php::Constant("CONSTANT_NAME", "value"));
 *  myclass.add(Php::Constant("CLASS_CONSTANT", "value"));
 * 
 *  @author Emiel Bruijntjes <emiel.bruijntjes@copernica.com>
 *  @copyright 2015 Copernica BV
 */

/**
 *  Set up namespace
 */
namespace Php {

/**
 *  Forward declarations
 */
class ConstantImpl;

/**
 *  Class definition
 */
class Constant
{
public:
    /**
     *  Constructor
     *  @param  name            Constant name
     *  @param  value           Constant value
     *  @param  size            Size of the value (in case of a string)
     */
    Constant(const char *name, std::nullptr_t value = nullptr);
    Constant(const char *name, bool value);
    Constant(const char *name, int32_t value);
    Constant(const char *name, int64_t value);
    Constant(const char *name, double value);
    Constant(const char *name, const char *value);
    Constant(const char *name, const char *value, size_t size);
    Constant(const char *name, const std::string &value);
    
    /**
     *  Destructor
     */
    virtual ~Constant() {}

private:
    /**
     *  Pointer to the actual implementation of the constant
     *  @var    std::shared_ptr
     */
    std::shared_ptr<ConstantImpl> _impl;

    /**
     *  Get access to the implementation object
     *  @return std::shared_ptr
     */
    const std::shared_ptr<ConstantImpl> &implementation() const { return _impl; }
    
    /**
     *  The extension object has access to privates
     */
    friend class ExtensionImpl;

};    
    
/**
 *  End of namespace
 */
}

