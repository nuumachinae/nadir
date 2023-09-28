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
///   Date: 9/26/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_IO_INPUT_HPP
#define XOS_IO_INPUT_HPP

#include "xos/base/string.hpp"
#include "xos/base/locked.hpp"
#include <stdarg.h>

namespace xos {
namespace io {

/// class inputt
template
<typename TChar = char, typename TEndChar = TChar, TEndChar VEndChar = 0,
 class TLocked = locked, class TImplements = TLocked>

class exported inputt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef inputt derives;

    typedef stringt<TChar> string_t;
    typedef TChar char_t;
    typedef TEndChar end_char_t;
    enum { end_char = VEndChar };

    typedef char_t what_t;
    typedef char_t sized_t;

    /// constructors / destructor
    virtual ~inputt() {
    }

    /// in...
    virtual ssize_t inf(const sized_t *format, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, format);
        count = this->infv(format, va);
        va_end(va);
        return count;
    }
    virtual ssize_t infv(const sized_t *format, va_list va) {
        return 0;
    }
    virtual ssize_t in(what_t *what, size_t size) {
        return 0;
    }
    virtual ssize_t in_fill() {
        return 0;
    }

protected:
}; /// class inputt
typedef inputt<> input;

namespace extended {
/// class inputt
template
<class TInput = input, class TExtends = extend, class TImplements = TInput>

class exported inputt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef inputt derives;

    typedef TInput input_t;
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
        return 0;
    }
    virtual ssize_t in(what_t *what, size_t size) {
        return 0;
    }
    virtual ssize_t in_fill() {
        return 0;
    }

protected:
}; /// class inputt
typedef inputt<> input;
} /// namespace extended

namespace forwarded {
/// class inputt
template
<class TExtendsOutput = io::extended::input, class TInputTo = io::input,
 class TExtends = TExtendsOutput, class TImplements = typename TExtends::implements>

class exported inputt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef inputt derives;

    typedef TInputTo input_to_t;
    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };

    typedef char_t what_t;
    typedef char_t sized_t;

    /// constructors / destructor
    inputt(const inputt& copy): input_to_(0) {
    }
    inputt(input_to_t* input_to): input_to_(input_to) {
    }
    inputt(): input_to_(0) {
    }
    virtual ~inputt() {
    }

    /// in...
    virtual ssize_t infv(const sized_t *format, va_list va) {
        ssize_t count = 0;
        input_to_t* input_to = 0;
        if ((input_to = this->input_to())) {
            count = input_to->outfv(format, va);
        } else {
            count = extends::infv(format, va);
        }
        return count;
    }
    virtual ssize_t in(what_t *what, size_t size) {
        ssize_t count = 0;
        input_to_t* input_to = 0;
        if ((input_to = this->input_to())) {
            count = input_to->in(what, size);
        } else {
            count = extends::in(what, size);
        }
        return count;
    }
    virtual ssize_t in_fill() {
        ssize_t count = 0;
        input_to_t* input_to = 0;
        if ((input_to = this->input_to())) {
            count = input_to->in_fill();
        } else {
            count = extends::in_fill();
        }
        return count;
    }

    /// ...input_to
    virtual input_to_t* set_input_to(input_to_t* to) {
        input_to_t *&input_to = this->input_to(), *old_input_to = input_to;
        input_to = to;
        return old_input_to;
    }
    virtual input_to_t* unset_input_to() {
        input_to_t *&input_to = this->input_to(), *old_input_to = input_to;
        input_to = 0;
        return old_input_to;
    }
protected:
    virtual input_to_t*& input_to() const {
        return (input_to_t*&)input_to_;
    }

protected:
    input_to_t* input_to_;
}; /// class inputt
typedef inputt<> input;
} /// namespace forwarded

} /// namespace io 
} /// namespace xos 

#endif /// ndef XOS_IO_INPUT_HPP
