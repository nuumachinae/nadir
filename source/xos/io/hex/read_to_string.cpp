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
///   File: read_to_string.cpp
///
/// Author: $author$
///   Date: 8/19/2023
//////////////////////////////////////////////////////////////////////////
#include "xos/io/hex/read_to_string.hpp"

#if !defined(XOS_IO_HEX_READ_TO_STRING_INSTANCE)
///#define XOS_IO_HEX_READ_TO_STRING_INSTANCE
#endif /// !defined(XOS_IO_HEX_READ_TO_STRING_INSTANCE)

namespace xos {
namespace io {
namespace hex {

///  Class: read_to_stringt
#if defined(XOS_IO_HEX_READ_TO_STRING_INSTANCE)
static read_to_string the_read_to_string;
#endif /// defined(XOS_IO_HEX_READ_TO_STRING_INSTANCE)

} /// namespace hex 
} /// namespace io 
} /// namespace xos 
