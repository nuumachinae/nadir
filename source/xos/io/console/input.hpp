//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2023 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: input.hpp
///
/// Author: $author$
///   Date: 9/28/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_IO_CONSOLE_INPUT_HPP
#define XOS_IO_CONSOLE_INPUT_HPP

#include "xos/io/crt/file/input.hpp"
#include "xos/console/io.hpp"

namespace xos {
namespace io {
namespace console {

/// class inputt
template 
<class TExtendsOutput = crt::file::input, 
 class TExtends = TExtendsOutput, class TImplements = typename TExtends::implements>

class exported inputt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef inputt derives; 
    
    typedef typename extends::file_t file_t;
    typedef typename extends::input_t input_t;
    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };

    typedef char_t what_t;
    typedef char_t sized_t;

    /// constructors / destructor
    inputt(const inputt& copy) {
    }
    inputt() {
    }
    virtual ~inputt() {
    }

    /// in...
    virtual ssize_t infv(const sized_t *format, va_list va) {
        ssize_t count = 0;
        file_t f = in_std_in();
        count = xos::console::infv(f, format, va);
        return count;
    }
    virtual ssize_t in(what_t *what, size_t size) {
        ssize_t count = 0;
        file_t f = in_std_in();
        count = xos::console::in(f, what, size);
        return count;
    }
    virtual ssize_t in_fill() {
        ssize_t count = 0;
        file_t f = in_std_in();
        count = xos::console::in_fill(f);
        return count;
    }

protected:
    virtual file_t in_std_in() const {
        return std_in();
    }
    virtual file_t std_in() const {
        return (file_t)stdin;
    }

protected:
}; /// class inputt
typedef inputt<> input;

} /// namespace console 
} /// namespace io 
} /// namespace xos 

#endif /// ndef XOS_IO_CONSOLE_INPUT_HPP
