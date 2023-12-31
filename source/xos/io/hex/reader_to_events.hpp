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
///   File: reader_to_events.hpp
///
/// Author: $author$
///   Date: 8/19/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_IO_HEX_READER_TO_EVENTS_HPP
#define XOS_IO_HEX_READER_TO_EVENTS_HPP

#include "xos/io/delegated/reader.hpp"
#include "xos/base/logger.hpp"

namespace xos {
namespace io {
namespace hex {

/// class reader_to_eventst
template 
<class TReader = xos::io::reader, 
 class TReaderEvents = xos::io::delegated::reader_eventst<TReader>, class TImplements = TReaderEvents>

class exported reader_to_eventst: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef reader_to_eventst derives; 
    
    typedef char char_t;
    typedef TReader reader_t;
    typedef typename reader_t::what_t what_t;
    typedef typename reader_t::sized_t sized_t;

    /// constructors / destructor
    virtual ~reader_to_eventst() {
    }

    /// on...
    virtual ssize_t on_begin(what_t* what, size_t size) {
        return size;
    }
    virtual ssize_t on_end(what_t* what, size_t size) {
        return size;
    }
    virtual ssize_t on_hex_char(what_t* what, size_t size) {
        sized_t* sized = 0;

        if ((sized = ((sized_t*)what))) {
            char_t c = ((char_t)(*sized));
            uint8_t d = 0;

            if (16 > (d = hex_digit(c))) {
                return on_hex_digit(d, what, size);
            }
        }
        return size;
    }
    virtual ssize_t on_hex_digit(uint8_t d, what_t* what, size_t size) {
        return size;
    }
    virtual ssize_t on_end_hex_digit(uint8_t d, what_t* what, size_t size) {
        return size;
    }

    /// ...hex...
    inline uint8_t hex_digit(const char_t& c) const {
        uint8_t d = 0;
        if (((char_t)('A') <= c) && ((char_t)('F') >= c)) {
            d = ((c - (char_t)('A')) + 10);
        } else {
            if (((char_t)('a') <= c) && ((char_t)('f') >= c)) {
                d = ((c - (char_t)('a')) + 10);
            } else {
                if (((char_t)('0') <= c) && ((char_t)('9') >= c)) {
                    d = ((c - (char_t)('0')));
                } else {
                    LOGGER_LOG_ERROR("...unexpected invalid_hex_char(" << char_to_string(c) << ")");
                    d = ((uint8_t)-1);
                }
            }
        }
        return d;
    }

}; /// class reader_to_eventst
typedef reader_to_eventst<> reader_to_events;

} /// namespace hex 
} /// namespace io 
} /// namespace xos 

#endif /// ndef XOS_IO_HEX_READER_TO_EVENTS_HPP
