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
///   Date: 8/23/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_SERVER_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_SERVER_MAIN_OPT_HPP

#include "xos/app/console/base/main.hpp"

#define XOS_APP_CONSOLE_SERVER_MAIN_RECEIVE_OPT "receive"
#define XOS_APP_CONSOLE_SERVER_MAIN_RECEIVE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_SERVER_MAIN_RECEIVE_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_SERVER_MAIN_RECEIVE_OPTARG "[string]"
#define XOS_APP_CONSOLE_SERVER_MAIN_RECEIVE_OPTUSE "receive request"
#define XOS_APP_CONSOLE_SERVER_MAIN_RECEIVE_OPTVAL_S "R::"
#define XOS_APP_CONSOLE_SERVER_MAIN_RECEIVE_OPTVAL_C 'R'
#define XOS_APP_CONSOLE_SERVER_MAIN_RECEIVE_OPTION \
   {XOS_APP_CONSOLE_SERVER_MAIN_RECEIVE_OPT, \
    XOS_APP_CONSOLE_SERVER_MAIN_RECEIVE_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_SERVER_MAIN_RECEIVE_OPTARG_RESULT, \
    XOS_APP_CONSOLE_SERVER_MAIN_RECEIVE_OPTVAL_C}, \

#define XOS_APP_CONSOLE_SERVER_MAIN_REQUEST_OPT "request"
#define XOS_APP_CONSOLE_SERVER_MAIN_REQUEST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_SERVER_MAIN_REQUEST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_SERVER_MAIN_REQUEST_OPTARG "[string]"
#define XOS_APP_CONSOLE_SERVER_MAIN_REQUEST_OPTUSE "request received"
#define XOS_APP_CONSOLE_SERVER_MAIN_REQUEST_OPTVAL_S "r::"
#define XOS_APP_CONSOLE_SERVER_MAIN_REQUEST_OPTVAL_C 'r'
#define XOS_APP_CONSOLE_SERVER_MAIN_REQUEST_OPTION \
   {XOS_APP_CONSOLE_SERVER_MAIN_REQUEST_OPT, \
    XOS_APP_CONSOLE_SERVER_MAIN_REQUEST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_SERVER_MAIN_REQUEST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_SERVER_MAIN_REQUEST_OPTVAL_C}, \

#define XOS_APP_CONSOLE_SERVER_MAIN_RESPONSE_OPT "response"
#define XOS_APP_CONSOLE_SERVER_MAIN_RESPONSE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_SERVER_MAIN_RESPONSE_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_SERVER_MAIN_RESPONSE_OPTARG "[string]"
#define XOS_APP_CONSOLE_SERVER_MAIN_RESPONSE_OPTUSE "response to send"
#define XOS_APP_CONSOLE_SERVER_MAIN_RESPONSE_OPTVAL_S "s::"
#define XOS_APP_CONSOLE_SERVER_MAIN_RESPONSE_OPTVAL_C 's'
#define XOS_APP_CONSOLE_SERVER_MAIN_RESPONSE_OPTION \
   {XOS_APP_CONSOLE_SERVER_MAIN_RESPONSE_OPT, \
    XOS_APP_CONSOLE_SERVER_MAIN_RESPONSE_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_SERVER_MAIN_RESPONSE_OPTARG_RESULT, \
    XOS_APP_CONSOLE_SERVER_MAIN_RESPONSE_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_SERVER_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_SERVER_MAIN_RECEIVE_OPTVAL_S \
   XOS_APP_CONSOLE_SERVER_MAIN_REQUEST_OPTVAL_S \
   XOS_APP_CONSOLE_SERVER_MAIN_RESPONSE_OPTVAL_S \

#define XOS_APP_CONSOLE_SERVER_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_SERVER_MAIN_RECEIVE_OPTION \
   XOS_APP_CONSOLE_SERVER_MAIN_REQUEST_OPTION \
   XOS_APP_CONSOLE_SERVER_MAIN_RESPONSE_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_SERVER_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_SERVER_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_SERVER_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_SERVER_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_SERVER_MAIN_ARGS 0
#define XOS_APP_CONSOLE_SERVER_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace server {

/// class main_optt
template 
<class TExtends = xos::app::console::base::maint<>,  class TImplements = typename TExtends::implements>

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
    main_optt(): run_(0) {
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

    typedef typename extends::string_reader_t string_reader_t;
    typedef typename extends::reader_string_t reader_string_t;
    typedef typename extends::reader_char_t reader_char_t;
    typedef typename extends::hex_read_to_string_t hex_read_to_string_t;
    typedef typename extends::hex_reader_t hex_reader_t;

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

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    /// on...receive_option...
    virtual int on_get_receive_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_receive_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_input_request_run(argc, argv, env))) {
            if (!(err = this->input_request_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_receive_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_receive_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_receive_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_receive_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_receive_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_receive_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_receive_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* receive_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_SERVER_MAIN_RECEIVE_OPTUSE;
        optarg = XOS_APP_CONSOLE_SERVER_MAIN_RECEIVE_OPTARG;
        return chars;
    }

    /// on...request_option...
    virtual int on_get_request_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_request_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_output_request_run(argc, argv, env))) {
            if (!(err = this->output_request_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_request_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t& request = this->request();
            if (!(err = this->on_set_string_message_option(request, optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_request_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_process_request_run(argc, argv, env))) {
            if (!(err = this->process_request_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_request_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_request_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_request_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_request_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_request_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* request_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_SERVER_MAIN_REQUEST_OPTUSE;
        optarg = XOS_APP_CONSOLE_SERVER_MAIN_REQUEST_OPTARG;
        return chars;
    }

    /// on...response_option...
    virtual int on_get_response_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_response_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_output_response_run(argc, argv, env))) {
            if (!(err = this->output_response_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_response_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t& response = this->response();
            if (!(err = this->on_set_string_message_option(response, optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_response_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_output_response_run(argc, argv, env))) {
            if (!(err = this->output_response_run_set(argc, argv, env))) {
                if (!(err = this->set_response_prepare_response_to_request_run(argc, argv, env))) {
                    if (!(err = this->response_prepare_response_to_request_run_set(argc, argv, env))) {
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_response_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_response_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_response_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_response_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_response_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* response_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_SERVER_MAIN_RESPONSE_OPTUSE;
        optarg = XOS_APP_CONSOLE_SERVER_MAIN_RESPONSE_OPTARG;
        return chars;
    }

    /// on_option
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_SERVER_MAIN_RECEIVE_OPTVAL_C:
            err = this->on_receive_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_SERVER_MAIN_REQUEST_OPTVAL_C:
            err = this->on_request_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_SERVER_MAIN_RESPONSE_OPTVAL_C:
            err = this->on_response_option(optval, optarg, optname, optind, argc, argv, env);
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

        case XOS_APP_CONSOLE_SERVER_MAIN_RECEIVE_OPTVAL_C:
            chars = this->receive_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_SERVER_MAIN_REQUEST_OPTVAL_C:
            chars = this->request_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_SERVER_MAIN_RESPONSE_OPTVAL_C:
            chars = this->response_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }

    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_SERVER_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_SERVER_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_SERVER_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_SERVER_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

protected:
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace server 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_SERVER_MAIN_OPT_HPP
