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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 6/21/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_VERBOSE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_VERBOSE_MAIN_OPT_HPP

#include "xos/app/console/framework/version/main.hpp"

#define XOS_APP_CONSOLE_VERBOSE_MAIN_VERBOSE_OPT "verbose"
#define XOS_APP_CONSOLE_VERBOSE_MAIN_VERBOSE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_VERBOSE_MAIN_VERBOSE_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_VERBOSE_MAIN_VERBOSE_OPTARG ""
#define XOS_APP_CONSOLE_VERBOSE_MAIN_VERBOSE_OPTUSE "verbose output"
#define XOS_APP_CONSOLE_VERBOSE_MAIN_VERBOSE_OPTVAL_S "v"
#define XOS_APP_CONSOLE_VERBOSE_MAIN_VERBOSE_OPTVAL_C 'v'
#define XOS_APP_CONSOLE_VERBOSE_MAIN_VERBOSE_OPTION \
   {XOS_APP_CONSOLE_VERBOSE_MAIN_VERBOSE_OPT, \
    XOS_APP_CONSOLE_VERBOSE_MAIN_VERBOSE_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_VERBOSE_MAIN_VERBOSE_OPTARG_RESULT, \
    XOS_APP_CONSOLE_VERBOSE_MAIN_VERBOSE_OPTVAL_C}, \

#define XOS_APP_CONSOLE_VERBOSE_MAIN_QUIET_OPT "quiet"
#define XOS_APP_CONSOLE_VERBOSE_MAIN_QUIET_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_VERBOSE_MAIN_QUIET_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_VERBOSE_MAIN_QUIET_OPTARG ""
#define XOS_APP_CONSOLE_VERBOSE_MAIN_QUIET_OPTUSE "quiet output"
#define XOS_APP_CONSOLE_VERBOSE_MAIN_QUIET_OPTVAL_S "q"
#define XOS_APP_CONSOLE_VERBOSE_MAIN_QUIET_OPTVAL_C 'q'
#define XOS_APP_CONSOLE_VERBOSE_MAIN_QUIET_OPTION \
   {XOS_APP_CONSOLE_VERBOSE_MAIN_QUIET_OPT, \
    XOS_APP_CONSOLE_VERBOSE_MAIN_QUIET_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_VERBOSE_MAIN_QUIET_OPTARG_RESULT, \
    XOS_APP_CONSOLE_VERBOSE_MAIN_QUIET_OPTVAL_C}, \

#define XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPT "64"
#define XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPTARG ""
#define XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPTUSE "base 64 output"
#define XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPTVAL_S "4"
#define XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPTVAL_C '4'
#define XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPTION \
   {XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPT, \
    XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPTARG_RESULT, \
    XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPTVAL_C}, \

#define XOS_APP_CONSOLE_VERBOSE_MAIN_LOWER_HEX_OPT "x"
#define XOS_APP_CONSOLE_VERBOSE_MAIN_LOWER_HEX_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_VERBOSE_MAIN_LOWER_HEX_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_VERBOSE_MAIN_LOWER_HEX_OPTARG ""
#define XOS_APP_CONSOLE_VERBOSE_MAIN_LOWER_HEX_OPTUSE "lower case hex output"
#define XOS_APP_CONSOLE_VERBOSE_MAIN_LOWER_HEX_OPTVAL_S "x"
#define XOS_APP_CONSOLE_VERBOSE_MAIN_LOWER_HEX_OPTVAL_C 'x'
#define XOS_APP_CONSOLE_VERBOSE_MAIN_LOWER_HEX_OPTION \
   {XOS_APP_CONSOLE_VERBOSE_MAIN_LOWER_HEX_OPT, \
    XOS_APP_CONSOLE_VERBOSE_MAIN_LOWER_HEX_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_VERBOSE_MAIN_LOWER_HEX_OPTARG_RESULT, \
    XOS_APP_CONSOLE_VERBOSE_MAIN_LOWER_HEX_OPTVAL_C}, \

#define XOS_APP_CONSOLE_VERBOSE_MAIN_UPPER_HEX_OPT "X"
#define XOS_APP_CONSOLE_VERBOSE_MAIN_UPPER_HEX_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_VERBOSE_MAIN_UPPER_HEX_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_VERBOSE_MAIN_UPPER_HEX_OPTARG ""
#define XOS_APP_CONSOLE_VERBOSE_MAIN_UPPER_HEX_OPTUSE "upper case hex output"
#define XOS_APP_CONSOLE_VERBOSE_MAIN_UPPER_HEX_OPTVAL_S "X"
#define XOS_APP_CONSOLE_VERBOSE_MAIN_UPPER_HEX_OPTVAL_C 'X'
#define XOS_APP_CONSOLE_VERBOSE_MAIN_UPPER_HEX_OPTION \
   {XOS_APP_CONSOLE_VERBOSE_MAIN_UPPER_HEX_OPT, \
    XOS_APP_CONSOLE_VERBOSE_MAIN_UPPER_HEX_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_VERBOSE_MAIN_UPPER_HEX_OPTARG_RESULT, \
    XOS_APP_CONSOLE_VERBOSE_MAIN_UPPER_HEX_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPTVAL_S \

#define XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_VERBOSE_MAIN_HEX_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_VERBOSE_MAIN_LOWER_HEX_OPTVAL_S \
   XOS_APP_CONSOLE_VERBOSE_MAIN_UPPER_HEX_OPTVAL_S \

#define XOS_APP_CONSOLE_VERBOSE_MAIN_HEX_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_VERBOSE_MAIN_LOWER_HEX_OPTION \
   XOS_APP_CONSOLE_VERBOSE_MAIN_UPPER_HEX_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_VERBOSE_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_VERBOSE_MAIN_QUIET_OPTVAL_S \
   XOS_APP_CONSOLE_VERBOSE_MAIN_VERBOSE_OPTVAL_S \

#define XOS_APP_CONSOLE_VERBOSE_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_VERBOSE_MAIN_QUIET_OPTION \
   XOS_APP_CONSOLE_VERBOSE_MAIN_VERBOSE_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_VERBOSE_MAIN_HEX_OPTIONS_CHARS \
   XOS_APP_CONSOLE_VERBOSE_MAIN_HEX_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_VERBOSE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_FRAMEWORK_VERSION_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_VERBOSE_MAIN_HEX_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_VERBOSE_MAIN_HEX_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_VERBOSE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_FRAMEWORK_VERSION_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_VERBOSE_MAIN_OUTPUT_OPTIONS_CHARS \
   XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_VERBOSE_MAIN_HEX_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_VERBOSE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_FRAMEWORK_VERSION_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_VERBOSE_MAIN_OUTPUT_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_VERBOSE_MAIN_HEX_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_VERBOSE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_FRAMEWORK_VERSION_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_VERBOSE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_VERBOSE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_FRAMEWORK_VERSION_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_VERBOSE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_VERBOSE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_FRAMEWORK_VERSION_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_VERBOSE_MAIN_ARGS 0
#define XOS_APP_CONSOLE_VERBOSE_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace verbose {

/// class main_optt
template
<class TExtends = xos::app::console::framework::version::maint<>,  class TImplements = typename TExtends::implements>

class main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    main_optt()
    : run_(0),
      output_x_(0),
      output_base64_(0),
      output_hex_(0),
      output_upper_hex_(0),
      output_lower_hex_(0),
      verbose_output_(false),
      output_lf_(true) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt &copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    /// run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }

    /// ...output_x
    ssize_t (derives::*output_x_)(const void* bytes, size_t length, bool lf);
    virtual ssize_t output_x(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        if (output_x_) {
            if (0 <= (amount = (this->*output_x_)(bytes, length, lf))) {
            } else {
            }
        } else {
            if (0 <= (amount = default_output_x(bytes, length, lf))) {
            } else {
            }
        }
        return amount;
    }
    virtual ssize_t default_output_x(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        if (0 <= (amount = all_output_hex(bytes, length, lf))) {
        } else {
        }
        return amount;
    }
    virtual ssize_t before_output_x(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        return amount;
    }
    virtual ssize_t after_output_x(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        return amount;
    }
    virtual ssize_t all_output_x(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        if (0 <= (amount = before_output_x(bytes, length, lf))) {
            ssize_t amount2 = 0;
            if (0 <= (amount2 = output_x(bytes, length, lf))) {
                amount += amount2;
                if (0 <= (amount2 = after_output_x(bytes, length, lf))) {
                    amount += amount2;
                }
            }
        }
        return amount;
    }
    virtual int set_output_base64(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_x_ = &derives::all_output_base64;
        return err;
    }
    virtual int output_base64_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_base64(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_x_ = 0;
        return err;
    }
    virtual int output_base64_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_output_hex(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_x_ = &derives::all_output_hex;
        return err;
    }
    virtual int output_hex_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_hex(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_x_ = 0;
        return err;
    }
    virtual int output_hex_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...output_base64
    ssize_t (derives::*output_base64_)(const void* bytes, size_t length, bool lf);
    virtual ssize_t output_base64(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        if (output_base64_) {
            if (0 <= (amount = (this->*output_base64_)(bytes, length, lf))) {
            } else {
            }
        } else {
            if (0 <= (amount = default_output_base64(bytes, length, lf))) {
            } else {
            }
        }
        return amount;
    }
    virtual ssize_t default_output_base64(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        if ((bytes) && (length)) {
            if ((lf)) {
                amount = this->out64ln(bytes, length);
            } else {
                amount = this->out64(bytes, length);
            }
        }
        return amount;
    }
    virtual ssize_t before_output_base64(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        return amount;
    }
    virtual ssize_t after_output_base64(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        return amount;
    }
    virtual ssize_t all_output_base64(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        if (0 <= (amount = before_output_base64(bytes, length, lf))) {
            ssize_t amount2 = 0;
            if (0 <= (amount2 = output_base64(bytes, length, lf))) {
                amount += amount2;
                if (0 <= (amount2 = after_output_base64(bytes, length, lf))) {
                    amount += amount2;
                }
            }
        }
        return amount;
    }

    /// ...output_hex
    ssize_t (derives::*output_hex_)(const void* bytes, size_t length, bool lf);
    virtual ssize_t output_hex(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        if (output_hex_) {
            if (0 <= (amount = (this->*output_hex_)(bytes, length, lf))) {
            } else {
            }
        } else {
            if (0 <= (amount = default_output_hex(bytes, length, lf))) {
            } else {
            }
        }
        return amount;
    }
    virtual ssize_t default_output_hex(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        if (0 <= (amount = all_output_lower_hex(bytes, length, lf))) {
        } else {
        }
        return amount;
    }
    virtual ssize_t before_output_hex(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        return amount;
    }
    virtual ssize_t after_output_hex(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        return amount;
    }
    virtual ssize_t all_output_hex(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        if (0 <= (amount = before_output_hex(bytes, length, lf))) {
            ssize_t amount2 = 0;
            if (0 <= (amount2 = output_hex(bytes, length, lf))) {
                amount += amount2;
                if (0 <= (amount2 = after_output_hex(bytes, length, lf))) {
                    amount += amount2;
                }
            }
        }
        return amount;
    }
    virtual int set_output_lower_hex(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_hex_ = &derives::all_output_lower_hex;
        return err;
    }
    virtual int output_lower_hex_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_lower_hex(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_hex_ = 0;
        return err;
    }
    virtual int output_lower_hex_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_output_upper_hex(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_hex_ = &derives::all_output_upper_hex;
        return err;
    }
    virtual int output_upper_hex_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_upper_hex(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_hex_ = 0;
        return err;
    }
    virtual int output_upper_hex_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...output_upper_hex
    ssize_t (derives::*output_upper_hex_)(const void* bytes, size_t length, bool lf);
    virtual ssize_t output_upper_hex(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        if (output_upper_hex_) {
            if (0 <= (amount = (this->*output_upper_hex_)(bytes, length, lf))) {
            } else {
            }
        } else {
            if (0 <= (amount = default_output_upper_hex(bytes, length, lf))) {
            } else {
            }
        }
        return amount;
    }
    virtual ssize_t default_output_upper_hex(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        if ((bytes) && (length)) {
            if ((lf)) {
                amount = this->outXln(bytes, length);
            } else {
                amount = this->outX(bytes, length);
            }
        }
        return amount;
    }
    virtual ssize_t before_output_upper_hex(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        return amount;
    }
    virtual ssize_t after_output_upper_hex(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        return amount;
    }
    virtual ssize_t all_output_upper_hex(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        if (0 <= (amount = before_output_upper_hex(bytes, length, lf))) {
            ssize_t amount2 = 0;
            if (0 <= (amount2 = output_upper_hex(bytes, length, lf))) {
                amount += amount2;
                if (0 <= (amount2 = after_output_upper_hex(bytes, length, lf))) {
                    amount += amount2;
                }
            }
        }
        return amount;
    }

    /// ...output_lower_hex
    ssize_t (derives::*output_lower_hex_)(const void* bytes, size_t length, bool lf);
    virtual ssize_t output_lower_hex(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        if (output_lower_hex_) {
            if (0 <= (amount = (this->*output_lower_hex_)(bytes, length, lf))) {
            } else {
            }
        } else {
            if (0 <= (amount = default_output_lower_hex(bytes, length, lf))) {
            } else {
            }
        }
        return amount;
    }
    virtual ssize_t default_output_lower_hex(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        if ((bytes) && (length)) {
            if ((lf)) {
                amount = this->outxln(bytes, length);
            } else {
                amount = this->outx(bytes, length);
            }
        }
        return amount;
    }
    virtual ssize_t before_output_lower_hex(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        return amount;
    }
    virtual ssize_t after_output_lower_hex(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        return amount;
    }
    virtual ssize_t all_output_lower_hex(const void* bytes, size_t length, bool lf = false) {
        ssize_t amount = 0;
        if (0 <= (amount = before_output_lower_hex(bytes, length, lf))) {
            ssize_t amount2 = 0;
            if (0 <= (amount2 = output_lower_hex(bytes, length, lf))) {
                amount += amount2;
                if (0 <= (amount2 = after_output_lower_hex(bytes, length, lf))) {
                    amount += amount2;
                }
            }
        }
        return amount;
    }

    /// ...output_text
    ssize_t (derives::*output_text_)(const char_t* chars, size_t length, bool lf);
    virtual ssize_t output_text(const char_t* chars, size_t length, bool lf = false) {
        ssize_t amount = 0;
        if (output_text_) {
            if (0 <= (amount = (this->*output_text_)(chars, length, lf))) {
            } else {
            }
        } else {
            if (0 <= (amount = default_output_text(chars, length, lf))) {
            } else {
            }
        }
        return amount;
    }
    virtual ssize_t default_output_text(const char_t* chars, size_t length, bool lf = false) {
        ssize_t amount = 0;
        if ((chars) && (length)) {
            if ((lf)) {
                amount = this->outln(chars, length);
            } else {
                amount = this->outx(chars, length);
            }
        }
        return amount;
    }
    virtual ssize_t before_output_text(const char_t* chars, size_t length, bool lf = false) {
        ssize_t amount = 0;
        return amount;
    }
    virtual ssize_t after_output_text(const char_t* chars, size_t length, bool lf = false) {
        ssize_t amount = 0;
        return amount;
    }
    virtual ssize_t all_output_text(const char_t* chars, size_t length, bool lf = false) {
        ssize_t amount = 0;
        if (0 <= (amount = before_output_text(chars, length, lf))) {
            ssize_t amount2 = 0;
            if (0 <= (amount2 = output_text(chars, length, lf))) {
                amount += amount2;
                if (0 <= (amount2 = after_output_text(chars, length, lf))) {
                    amount += amount2;
                }
            }
        }
        return amount;
    }

    /// on...base64_option...
    virtual int on_set_base64_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_base64(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_base64_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_base64_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_base64_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_base64_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* base64_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPTUSE;
        optarg = XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPTARG;
        return chars;
    }

    /// on...lower_hex_option...
    virtual int on_set_lower_hex_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_lower_hex(argc, argv, env))) {
            if (!(err = set_output_hex(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_lower_hex_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_lower_hex_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_lower_hex_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_lower_hex_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* lower_hex_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_VERBOSE_MAIN_LOWER_HEX_OPTUSE;
        optarg = XOS_APP_CONSOLE_VERBOSE_MAIN_LOWER_HEX_OPTARG;
        return chars;
    }

    /// on...upper_hex_option...
    virtual int on_set_upper_hex_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_upper_hex(argc, argv, env))) {
            if (!(err = set_output_hex(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_upper_hex_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_upper_hex_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_upper_hex_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_upper_hex_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* upper_hex_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_VERBOSE_MAIN_UPPER_HEX_OPTUSE;
        optarg = XOS_APP_CONSOLE_VERBOSE_MAIN_UPPER_HEX_OPTARG;
        return chars;
    }

    /// on...quiet_option...
    virtual int on_set_quiet_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        set_quiet_output();
        return err;
    }
    virtual int on_quiet_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_quiet_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_quiet_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_quiet_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* quiet_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_VERBOSE_MAIN_QUIET_OPTUSE;
        optarg = XOS_APP_CONSOLE_VERBOSE_MAIN_QUIET_OPTARG;
        return chars;
    }

    /// on...verbose_option...
    virtual int on_set_verbose_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        set_verbose_output();
        return err;
    }
    virtual int on_verbose_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_verbose_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_verbose_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_verbose_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* verbose_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_VERBOSE_MAIN_VERBOSE_OPTUSE;
        optarg = XOS_APP_CONSOLE_VERBOSE_MAIN_VERBOSE_OPTARG;
        return chars;
    }

    /// on_option
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPTVAL_C:
            err = this->on_base64_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_VERBOSE_MAIN_LOWER_HEX_OPTVAL_C:
            err = this->on_lower_hex_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_VERBOSE_MAIN_UPPER_HEX_OPTVAL_C:
            err = this->on_upper_hex_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_VERBOSE_MAIN_QUIET_OPTVAL_C:
            err = this->on_quiet_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_VERBOSE_MAIN_VERBOSE_OPTVAL_C:
            err = this->on_verbose_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }

    /// option_usage
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_VERBOSE_MAIN_BASE64_OPTVAL_C:
            chars = this->base64_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_VERBOSE_MAIN_LOWER_HEX_OPTVAL_C:
            chars = this->lower_hex_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_VERBOSE_MAIN_UPPER_HEX_OPTVAL_C:
            chars = this->upper_hex_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_VERBOSE_MAIN_QUIET_OPTVAL_C:
            chars = this->quiet_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_VERBOSE_MAIN_VERBOSE_OPTVAL_C:
            chars = this->verbose_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }

    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_VERBOSE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_VERBOSE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_VERBOSE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_VERBOSE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    /// ...verbose_output
    virtual bool& set_quiet_output(const bool& to = true) {
        bool& verbose_output = this->verbose_output();
        verbose_output = !to;
        return verbose_output;
    }
    virtual bool& set_verbose_output(const bool& to = true) {
        bool& verbose_output = this->verbose_output();
        verbose_output = to;
        return verbose_output;
    }
    virtual bool& verbose_output() const {
        return (bool&)verbose_output_;
    }

    virtual bool& set_output_lf(const bool& to = true) {
        bool& output_lf = this->output_lf();
        output_lf = to;
        return output_lf;
    }
    virtual bool& output_lf() const {
        return (bool&)output_lf_;
    }

protected:
    bool verbose_output_, output_lf_;
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace verbose
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_VERBOSE_MAIN_OPT_HPP
