#ifndef __ARRAY_PROXY__
#define __ARRAY_PROXY__

#include <boost/python.hpp>

/** Type that proxies to an C array.
 *  Optionally converts to another type on element access */
template <typename value_type, typename ItemType>
class ArrayProxy
{
public:
  // Types
  typedef value_type* iterator;
  typedef value_type& reference;
  typedef std::size_t size_type;

  /// @brief Empty constructor.
  ArrayProxy(iterator buffer, size_type length) : data(buffer), length(length)  {}

  size_type size() const { return length; }

  ItemType get_item(size_type index) const { return ItemType(get_item_reference(index)); }

  void set_item(reference item, size_type index) { get_item_reference(index) = item; }

private:
  value_type  *data;
  std::size_t length;

  size_type checkIndex(size_type index) const
  {
    // Adjust negative index.
    if (index < 0)
        index += length;

    // Boundary check.
    if (index < 0 || index >= length) {
      PyErr_SetString(PyExc_IndexError, "Index out of range");
      boost::python::throw_error_already_set();
    }

    return index;
  }

  reference get_item_reference(size_t index) const { return data[checkIndex(index)]; }
};

#endif // __ARRAY_PROXY__
