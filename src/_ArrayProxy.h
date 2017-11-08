#ifndef __ARRAY_PROXY__
#define __ARRAY_PROXY__

#include <boost/python.hpp>

/** Type that proxies to an C array.
 *  Optionally converts to another type on element access and holds reference to buffer's parent object.
 *  @param value_type  buffer element type
 *  @param ItemType    returned object type for element access
 *  @param Parent      type of parent copy held by proxy (use void* if not needed and NULL as parent in constructor)
 */
template <typename value_type, typename ItemType, typename Parent>
class ArrayProxy
{
public:
  // Types
  typedef value_type* iterator;
  typedef value_type& reference;
  typedef std::size_t size_type;

  /** @brief Default constructor
   *  @param buffer  C-style array to be proxied
   *  @param length  number of elements in buffer (size in bytes / sizeof(value_type))
   *  @param parent  buffer's parent object. We hold copy-constructed value for managing lifetime
   */
  ArrayProxy(iterator buffer, size_type length, const Parent &parent) : data(buffer), length(length), parent(parent)  {}

  size_type size() const { return length; }

  ItemType get_item(size_type index) const { return ItemType(get_item_reference(index)); }

  void set_item(reference item, size_type index) { get_item_reference(index) = item; }

private:
  value_type  *data;
  std::size_t length;
  Parent parent;

  size_type checkIndex(size_type index) const
  {
    // Boundary check.
    if (index >= length) {
      PyErr_SetString(PyExc_IndexError, "Index out of range");
      boost::python::throw_error_already_set();
    }

    return index;
  }

  reference get_item_reference(size_t index) const { return data[checkIndex(index)]; }
};

#endif // __ARRAY_PROXY__
