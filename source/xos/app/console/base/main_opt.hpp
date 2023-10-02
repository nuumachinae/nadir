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
///   Date: 8/19/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_BASE_MAIN_OPT_HPP

#include "xos/app/console/verbose/main.hpp"

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_CHARS_EXTEND \

#define XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_VERBOSE_MAIN_INPUT_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_VERBOSE_MAIN_INPUT_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_BASE_MAIN_ARGS 0
#define XOS_APP_CONSOLE_BASE_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace base {

/// class main_optt
template 
<class TExtends = xos::app::console::verbose::maint<>,  class TImplements = typename TExtends::implements>

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
      restart_(false), start_(false), stop_(false),
      request_("request"), response_("response"), 
      known_request_(request_), known_response_(response_),
      unknown_request_("unknown"), unknown_response_(unknown_request_),
      crlf2_endof_message_("\r\n\r\n"), crlf_endof_message_("\r\n"), 
      cr_endof_message_("\r"), lf_endof_message_("\n") {
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

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

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
    /// ...process_request_run
    int (derives::*process_request_run_)(int argc, char_t** argv, char_t** env);
    virtual int process_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (process_request_run_) {
            if (!(err = (this->*process_request_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_process_request_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_process_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = all_prepare_response_run(argc, argv, env))...");
        if (!(err = all_prepare_response_run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(err = all_prepare_response_run(argc, argv, env))");
            LOGGER_IS_LOGGED_INFO("!(err = all_output_response_run(argc, argv, env))...");
            if (!(err = all_output_response_run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(err = all_output_response_run(argc, argv, env))");
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int before_process_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_request_run(argc, argv, env))) {
            int err2 = 0;
            err = process_request_run(argc, argv, env);
            if ((err2 = after_process_request_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_process_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_process_request_run;
        return err;
    }
    virtual int process_request_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_process_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int process_request_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...process_response_run
    int (derives::*process_response_run_)(int argc, char_t** argv, char_t** env);
    virtual int process_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (process_response_run_) {
            if (!(err = (this->*process_response_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_process_response_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_process_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = all_output_response_run(argc, argv, env))...");
        if (!(err = all_output_response_run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(err = all_output_response_run(argc, argv, env)");
        } else {
        }
        return err;
    }
    virtual int before_process_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_response_run(argc, argv, env))) {
            int err2 = 0;
            err = process_response_run(argc, argv, env);
            if ((err2 = after_process_response_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_process_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_process_response_run;
        return err;
    }
    virtual int process_response_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_process_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int process_response_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...input_request_run
    int (derives::*input_request_run_)(int argc, char_t** argv, char_t** env);
    virtual int input_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (input_request_run_) {
            err = (this->*input_request_run_)(argc, argv, env);
        } else {
            err = default_input_request_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_input_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& request = this->request();
        LOGGER_IS_LOGGED_INFO("!(err = all_input_request_run(request, argc, argv, env))...");
        if (!(err = all_input_request_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_input_request_run(request, argc, argv, env))");
            LOGGER_IS_LOGGED_INFO("!(err = all_process_request_run(argc, argv, env))...");
            if (!(err = all_process_request_run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_process_request_run(argc, argv, env))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_process_request_run(argc, argv, env))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_input_request_run(request, argc, argv, env))");
        }
        return err;
    }
    virtual int before_input_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_input_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_input_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_input_request_run(argc, argv, env))) {
            int err2 = 0;
            err = input_request_run(argc, argv, env);
            if ((err2 = after_input_request_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_input_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_input_request_run;
        return err;
    }
    virtual int input_request_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_input_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int input_request_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...output_request_run
    int (derives::*output_request_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_request_run_) {
            err = (this->*output_request_run_)(argc, argv, env);
        } else {
            err = default_output_request_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& request = this->request();
        LOGGER_IS_LOGGED_INFO("!(err = all_output_request_run(request, argc, argv, env))...");
        if (!(err = all_output_request_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_output_request_run(request, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_output_request_run(request, argc, argv, env))");
        }
        return err;
    }
    virtual int before_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_request_run(argc, argv, env))) {
            int err2 = 0;
            err = output_request_run(argc, argv, env);
            if ((err2 = after_output_request_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_request_run;
        return err;
    }
    virtual int output_request_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_request_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...output_response_run
    int (derives::*output_response_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_response_run_) {
            err = (this->*output_response_run_)(argc, argv, env);
        } else {
            err = default_output_response_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& response = this->response();
        LOGGER_IS_LOGGED_INFO("(err = all_output_response_run(response, argc, argv, env))...");
        if (!(err = all_output_response_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_output_response_run(response, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_output_response_run(response, argc, argv, env))");
        }
        return err;
    }
    virtual int before_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_response_run(argc, argv, env))) {
            int err2 = 0;
            err = output_response_run(argc, argv, env);
            if ((err2 = after_output_response_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_response_run;
        return err;
    }
    virtual int output_response_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_response_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    /// ...prepare_response_run
    int (derives::*prepare_response_run_)(int argc, char_t** argv, char_t** env);
    virtual int prepare_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_response_run_) {
            err = (this->*prepare_response_run_)(argc, argv, env);
        } else {
            err = default_prepare_response_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_prepare_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& request = this->request();
        const char_t* chars = 0; size_t length = 0;

        LOGGER_IS_LOGGED_INFO("(chars = request.has_chars(length))...");
        if ((chars = request.has_chars(length))) {
            string_t& response = this->response();
            
            LOGGER_IS_LOGGED_INFO("...(chars = request.has_chars(" << length << "))");
            LOGGER_IS_LOGGED_INFO("!(err = all_prepare_response_to_request_run(response, request, argc, argv, env))...");
            if (!(err = all_prepare_response_to_request_run(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_prepare_response_to_request_run(response, request, argc, argv, env))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_prepare_response_to_request_run(response, request, argc, argv, env))");
            }
        }
        return err;
    }
    virtual int before_prepare_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_run(argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_run(argc, argv, env);
            if ((err2 = after_prepare_response_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    /// ...process_request_run
    virtual int process_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& response = this->response();

        LOGGER_IS_LOGGED_INFO("!(err = all_prepare_response_to_request_run(response, request, argc, argv, env))...");
        if (!(err = all_prepare_response_to_request_run(response, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_prepare_response_to_request_run(response, request, argc, argv, env))");
            
            LOGGER_IS_LOGGED_INFO("!(err = all_output_response_run(response, argc, argv, env))...");
            if (!(err = all_output_response_run(response, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_output_response_run(response, argc, argv, env))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_output_response_run(response, argc, argv, env))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_prepare_response_to_request_run(response, request, argc, argv, env))");
        }
        return err;
    }
    virtual int before_process_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_request_run(request, argc, argv, env))) {
            int err2 = 0;
            err = process_request_run(request, argc, argv, env);
            if ((err2 = after_process_request_run(request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...process_response_run
    virtual int process_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = all_output_response_run(response, argc, argv, env))...");
        if (!(err = all_output_response_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_output_response_run(response, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_output_response_run(response, argc, argv, env))");
        }
        return err;
    }
    virtual int before_process_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_response_run(response, argc, argv, env))) {
            int err2 = 0;
            err = process_response_run(response, argc, argv, env);
            if ((err2 = after_process_response_run(response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_request_run
    int (derives::*prepare_response_to_request_run_)(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env);
    virtual int prepare_response_to_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_response_to_request_run_) {
            err = (this->*prepare_response_to_request_run_)(response, request, argc, argv, env);
        } else {
            err = default_prepare_response_to_request_run(response, request, argc, argv, env);
        }
        return err;
    }
    virtual int default_prepare_response_to_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = all_prepare_response_to_known_request_run(response, request, argc, argv, env))...");
        if (!(err = all_prepare_response_to_known_request_run(response, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_prepare_response_to_known_request_run(response, request, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_prepare_response_to_known_request_run(response, request, argc, argv, env))");
        }
        return err;
    }
    virtual int before_prepare_response_to_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_to_request_run(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_to_request_run(response, request, argc, argv, env);
            if ((err2 = after_prepare_response_to_request_run(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...response_prepare_response_to_request_run
    virtual int response_prepare_response_to_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_response_prepare_response_to_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_response_to_request_run_ = &derives::response_prepare_response_to_request_run;
        return err;
    }
    virtual int response_prepare_response_to_request_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_response_prepare_response_to_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_response_to_request_run_ = 0;
        return err;
    }
    virtual int response_prepare_response_to_request_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_known_request_run
    int (derives::*prepare_response_to_known_request_run_)(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env);
    virtual int prepare_response_to_known_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_response_to_known_request_run_) {
            if (!(err = (this->*prepare_response_to_known_request_run_)(response, request, argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_prepare_response_to_known_request_run(response, request, argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_prepare_response_to_known_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0, unequal = 0;
        const string_t& known_request = this->known_request();
        
        LOGGER_IS_LOGGED_INFO("!(unequal = request.compare(known_request))...");
        if (!(unequal = request.compare(known_request))) {
            const string_t& known_response = this->known_response();

            LOGGER_IS_LOGGED_INFO("...!(" << unequal << " = request.compare(known_request))");
            LOGGER_IS_LOGGED_INFO("response.assign(known_response = \"" << known_response << "\")...");
            response.assign(known_response);
        } else {
            LOGGER_IS_LOGGED_INFO("...(" << unequal << " = request.compare(known_request))");
            LOGGER_IS_LOGGED_INFO("!(err = all_prepare_response_to_unknown_request_run(response, request, argc, argv, env))...");
            if (!(err = all_prepare_response_to_unknown_request_run(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_prepare_response_to_unknown_request_run(response, request, argc, argv, env))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_prepare_response_to_unknown_request_run(response, request, argc, argv, env))");
            }
        }
        return err;
    }
    virtual int before_prepare_response_to_known_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_known_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_known_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_to_known_request_run(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_to_known_request_run(response, request, argc, argv, env);
            if ((err2 = after_prepare_response_to_known_request_run(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_unknown_request_run
    int (derives::*prepare_response_to_unknown_request_run_)(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env);
    virtual int prepare_response_to_unknown_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_response_to_unknown_request_run_) {
            if (!(err = (this->*prepare_response_to_unknown_request_run_)(response, request, argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_prepare_response_to_unknown_request_run(response, request, argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_prepare_response_to_unknown_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& unknown_response = this->unknown_response();
        LOGGER_IS_LOGGED_INFO("response.assign(unknown_response = \"" << unknown_response << "\")...");
        response.assign(unknown_response);
        return err;
    }
    virtual int before_prepare_response_to_unknown_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_unknown_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_unknown_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_to_unknown_request_run(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_to_unknown_request_run(response, request, argc, argv, env);
            if ((err2 = after_prepare_response_to_unknown_request_run(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...input_request_run
    virtual int input_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = all_input_message_run(request, argc, argv, env))...");
        if (!(err = all_input_message_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_input_message_run(request, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_input_message_run(request, argc, argv, env))");
        }
        return err;
    }
    virtual int before_input_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_input_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = all_prepare_request_input_run(request, argc, argv, env))...");
        if (!(err = all_prepare_request_input_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_prepare_request_input_run(request, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_prepare_request_input_run(request, argc, argv, env))");
        }
        return err;
    }
    virtual int all_input_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_input_request_run(request, argc, argv, env))) {
            int err2 = 0;
            err = input_request_run(request, argc, argv, env);
            if ((err2 = after_input_request_run(request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...output_request_run
    virtual int output_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = all_output_message_run(request, argc, argv, env))...");
        if (!(err = all_output_message_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_output_message_run(request, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_output_message_run(request, argc, argv, env))");
        }
        return err;
    }
    virtual int before_output_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = all_prepare_request_to_output_run(request, argc, argv, env))...");
        if (!(err = all_prepare_request_to_output_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_prepare_request_to_output_run(request, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_prepare_request_to_output_run(request, argc, argv, env))");
        }
        return err;
    }
    virtual int after_output_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_request_run(request, argc, argv, env))) {
            int err2 = 0;
            err = output_request_run(request, argc, argv, env);
            if ((err2 = after_output_request_run(request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...prepare_request_input_run
    virtual int prepare_request_input_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_request_input_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_request_input_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_request_input_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_request_input_run(request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_request_input_run(request, argc, argv, env);
            if ((err2 = after_prepare_request_input_run(request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...prepare_request_to_output_run
    virtual int prepare_request_to_output_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_request_to_output_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_request_to_output_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_request_to_output_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_request_to_output_run(request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_request_to_output_run(request, argc, argv, env);
            if ((err2 = after_prepare_request_to_output_run(request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...output_response_run
    virtual int output_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = all_output_message_run(response, argc, argv, env))...");
        if (!(err = all_output_message_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_output_message_run(response, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_output_message_run(response, argc, argv, env))");
        }
        return err;
    }
    virtual int before_output_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = all_prepare_response_to_output_run(response, argc, argv, env))...");
        if (!(err = all_prepare_response_to_output_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_prepare_response_to_output_run(response, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_prepare_response_to_output_run(response, argc, argv, env))");
        }
        return err;
    }
    virtual int after_output_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_response_run(response, argc, argv, env))) {
            int err2 = 0;
            err = output_response_run(response, argc, argv, env);
            if ((err2 = after_output_response_run(response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_output_run
    virtual int prepare_response_to_output_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_response_to_output_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_output_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_output_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_to_output_run(response, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_to_output_run(response, argc, argv, env);
            if ((err2 = after_prepare_response_to_output_run(response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...output_message_run
    virtual int output_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& out_message = message;
        LOGGER_IS_LOGGED_INFO("this->out(message = \"" << out_message << "\")...");
        this->out(out_message);
        return err;
    }
    virtual int before_output_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = all_prepare_message_to_output_run(message, argc, argv, env))...");
        if (!(err = all_prepare_message_to_output_run(message, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_prepare_message_to_output_run(message, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_prepare_message_to_output_run(message, argc, argv, env))");
        }
        return err;
    }
    virtual int after_output_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_message_run(message, argc, argv, env))) {
            int err2 = 0;
            err = output_message_run(message, argc, argv, env);
            if ((err2 = after_output_message_run(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...prepare_message_to_output_run
    virtual int prepare_message_to_output_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& endof_message = lf_endof_message();
        LOGGER_IS_LOGGED_INFO("message.append(endof_message = \"" << endof_message << "\")...");
        message.append(endof_message);
        return err;
    }
    virtual int before_prepare_message_to_output_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_message_to_output_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_message_to_output_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_message_to_output_run(message, argc, argv, env))) {
            int err2 = 0;
            err = prepare_message_to_output_run(message, argc, argv, env);
            if ((err2 = after_prepare_message_to_output_run(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...input_message_run
    virtual int input_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        char_t c = 0;
        in_reader_t reader(*this);
        string_t message_assign;
        
        LOGGER_IS_LOGGED_INFO("!(err = read(message_assign, c, reader, argc, argv, env))...");
        if (!(err = read(message_assign, c, reader, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = read(message_assign, c, reader, argc, argv, env))");
            LOGGER_IS_LOGGED_INFO("message.assign(message_assign)...");
            message.assign(message_assign);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = read(message_assign, c, reader, argc, argv, env))");
        }
        return err;
    }
    virtual int before_input_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_input_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = all_prepare_message_input_run(message, argc, argv, env))...");
        if (!(err = all_prepare_message_input_run(message, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_prepare_message_input_run(message, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_prepare_message_input_run(message, argc, argv, env))");
        }
        return err;
    }
    virtual int all_input_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_input_message_run(message, argc, argv, env))) {
            int err2 = 0;
            err = input_message_run(message, argc, argv, env);
            if ((err2 = after_input_message_run(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...prepare_message_input_run
    virtual int prepare_message_input_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = prepare_read(message, argc, argv, env))...");
        if (!(err = prepare_read(message, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = prepare_read(message, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = prepare_read(message, argc, argv, env))");
        }
        return err;
    }
    virtual int before_prepare_message_input_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_message_input_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_message_input_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_message_input_run(message, argc, argv, env))) {
            int err2 = 0;
            err = prepare_message_input_run(message, argc, argv, env);
            if ((err2 = after_prepare_message_input_run(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////

    /// ...read
    int (derives::*read_)(string_t& r, char_t& c, reader_t& reader, int argc, char_t** argv, char_t** env);
    virtual int read(string_t& r, char_t& c, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (read_) {
            if (!(err = (this->*read_)(r, c, reader, argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_read(r, c, reader, argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_read(string_t& r, char_t& c, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...!(err = read_lf(r, c, reader, argc, argv, env))");
        if (!(err = read_lf(r, c, reader, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = read_lf(r, c, reader, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = read_lf(r, c, reader, argc, argv, env))");
        }
        return err;
    }
    /// ...<cr>
    virtual int on_read_cr(string_t& r, char_t& c, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int read_cr(string_t& r, char_t& c, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, cr } s = ch;

        while (0 < (amount = reader.read(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                LOGGER_IS_LOGGED_INFO("...case '\\r':");
                switch (s) {
                case ch:
                    s = cr;
                    LOGGER_IS_LOGGED_INFO("err = on_read_cr(r, c, reader, argc, argv, env)...");
                    err = on_read_cr(r, c, reader, argc, argv, env);
                    return err;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                } /// switch (s)
                break;
            case '\n':
                LOGGER_IS_LOGGED_INFO("...case '\\n':");
                break;
            default:
                LOGGER_IS_LOGGED_INFO("...default:");
                break;
            } /// switch (c)
        } /// while (0 < (amount = reader.read(&c, 1)))
        return err;
    }
    /// ...<lf>
    virtual int on_read_lf(string_t& r, char_t& c, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int read_lf(string_t& r, char_t& c, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, lf } s = ch;

        while (0 < (amount = reader.read(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                LOGGER_IS_LOGGED_INFO("...case '\\r':");
                break;
            case '\n':
                LOGGER_IS_LOGGED_INFO("...case '\\n':");
                switch (s) {
                case ch:
                    s = lf;
                    LOGGER_IS_LOGGED_INFO("err = on_read_lf(r, c, reader, argc, argv, env)...");
                    err = on_read_lf(r, c, reader, argc, argv, env);
                    return err;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                } /// switch (s)
                break;
            default:
                LOGGER_IS_LOGGED_INFO("...default:");
                break;
            } /// switch (c)
        } /// while (0 < (amount = reader.read(&c, 1)))
        return err;
    }
    /// ...<cr><lf><cr><lf>
    virtual int on_read_crlf2(string_t& r, char_t& c, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int read_crlf2(string_t& r, char_t& c, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, cr, crlf, crlfcr } s = ch;

        while (0 < (amount = reader.read(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                LOGGER_IS_LOGGED_INFO("...case '\\r':");
                switch (s) {
                case ch:
                    s = cr;
                    break;
                case cr:
                    s = cr;
                    break;
                case crlf:
                    s = crlfcr;
                    break;
                case crlfcr:
                    s = cr;
                    break;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            case '\n':
                LOGGER_IS_LOGGED_INFO("...case '\\n':");
                switch (s) {
                case ch:
                    s = ch;
                    break;
                case crlf:
                    s = ch;
                    break;
                case cr:
                    s = crlf;
                    break;
                case crlfcr:
                    LOGGER_IS_LOGGED_INFO("err = on_read_crlf2(r, c, reader, argc, argv, env)...");
                    err = on_read_crlf2(r, c, reader, argc, argv, env);
                    return err;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            default:
                LOGGER_IS_LOGGED_INFO("...default:");
                s = ch;
                break;
            }
        }
        return err;
    }
    virtual int set_read_crlf2(int argc, char_t** argv, char_t** env) {
        int err = 0;
        read_ = &derives::read_crlf2;
        return err;
    }
    virtual int read_crlf2_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_read_crlf2(int argc, char_t** argv, char_t** env) {
        int err = 0;
        read_ = 0;
        return err;
    }
    virtual int crlf2_read_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...prepare_read
    int (derives::*prepare_read_)(string_t& r, int argc, char_t** argv, char_t** env);
    virtual int prepare_read(string_t& r, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_read_) {
            if (!(err = (this->*prepare_read_)(r, argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_prepare_read(r, argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_prepare_read(string_t& r, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = prepare_read_lf(r, argc, argv, env))...");
        if (!(err = prepare_read_lf(r, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = prepare_read_lf(r, argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = prepare_read_lf(r, argc, argv, env))");
        }
        return err;
    }
    /// ...<cr>
    virtual int prepare_read_cr(string_t& r, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        
        if ((chars = r.has_chars(length))) {
            enum { ch, cr } s = ch;
            size_t count = 0;
            string_t r_assign;

            for (count = length; count > 0; --count, ++chars) {
                char_t c = *chars;

                switch(c) {
                case '\r':
                    LOGGER_IS_LOGGED_INFO("...case '\\r':");
                    switch (s) {
                    case ch:
                        s = cr;
                        LOGGER_IS_LOGGED_INFO("r.assign(\"" << r_assign << "\")...");
                        r.assign(r_assign);
                        return err;
                    default:
                        LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                        return err = 1;
                    } /// switch (s)
                    break;
                case '\n':
                    LOGGER_IS_LOGGED_INFO("...case '\\n':");
                    r_assign.append(&c, 1);
                    break;
                default:
                    LOGGER_IS_LOGGED_INFO("...default:");
                    r_assign.append(&c, 1);
                    break;
                } /// switch(c) 
            } /// for (count = length; count > 0; --count, ++chars)
        }
        return err;
    }
    /// ...<lf>
    virtual int prepare_read_lf(string_t& r, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        
        if ((chars = r.has_chars(length))) {
            enum { ch, lf } s = ch;
            size_t count = 0;
            string_t r_assign;

            for (count = length; count > 0; --count, ++chars) {
                char_t c = *chars;

                switch(c) {
                case '\r':
                    LOGGER_IS_LOGGED_INFO("...case '\\r':");
                    r_assign.append(&c, 1);
                    break;
                case '\n':
                    LOGGER_IS_LOGGED_INFO("...case '\\n':");
                    switch (s) {
                    case ch:
                        s = lf;
                        LOGGER_IS_LOGGED_INFO("r.assign(\"" << r_assign << "\")...");
                        r.assign(r_assign);
                        return err;
                    default:
                        LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                        return err = 1;
                    } /// switch (s)
                    break;
                default:
                    LOGGER_IS_LOGGED_INFO("...default:");
                    r_assign.append(&c, 1);
                    break;
                } /// switch(c) 
            } /// for (count = length; count > 0; --count, ++chars)
        }
        return err;
    }
    /// ...<cr><lf><cr><lf>
    virtual int prepare_read_crlf2(string_t& r, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        
        if ((chars = r.has_chars(length))) {
            enum { ch, cr, crlf, crlfcr } s = ch;
            size_t count = 0;
            string_t r_append, r_assign;
            
            for (count = length; count > 0; --count, ++chars) {
                char_t c = *chars;
                r_append.append(&c, 1);
                switch(c) {
                case '\r':
                    LOGGER_IS_LOGGED_INFO("...case '\\r':");
                    switch (s) {
                    case ch:
                        s = cr;
                        break;
                    case cr:
                        s = cr;
                        r_assign.append(r_append);
                        r_append.clear();
                        break;
                    case crlf:
                        s = crlfcr;
                        break;
                    case crlfcr:
                        s = cr;
                        r_assign.append(r_append);
                        r_append.clear();
                        break;
                    default:
                        LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                        return err = 1;
                    }
                    break;
                case '\n':
                    LOGGER_IS_LOGGED_INFO("...case '\\n':");
                    switch (s) {
                    case ch:
                        s = ch;
                        r_assign.append(r_append);
                        r_append.clear();
                        break;
                    case crlf:
                        s = ch;
                        r_assign.append(r_append);
                        r_append.clear();
                        break;
                    case cr:
                        s = crlf;
                        break;
                    case crlfcr:
                        r.assign(r_assign);
                        return err;
                    default:
                        LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                        return err = 1;
                    }
                    break;
                default:
                    LOGGER_IS_LOGGED_INFO("...default:");
                    s = ch;
                    r_assign.append(r_append);
                    r_append.clear();
                    break;
                }
            }
        } else {
        }
        return err;
    }
    virtual int set_prepare_read_crlf2(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_read_ = &derives::prepare_read_crlf2;
        return err;
    }
    virtual int prepare_read_crlf2_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_prepare_read_crlf2(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_read_ = 0;
        return err;
    }
    virtual int prepare_read_crlf2_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////

    /// on_option
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    
    /// option_usage
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }

    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...endof_message
    /// ...
    /// ...crlf2_endof_message
    virtual string_t& set_crlf2_endof_message(const string_t& to) {
        string_t& crlf2_endof_message = this->crlf2_endof_message();
        crlf2_endof_message.assign(to);
        return crlf2_endof_message;
    }
    virtual string_t& set_crlf2_endof_message(const char_t* to, size_t length) {
        string_t& crlf2_endof_message = this->crlf2_endof_message();
        crlf2_endof_message.assign(to, length);
        return crlf2_endof_message;
    }
    virtual string_t& set_crlf2_endof_message(const char_t* to) {
        string_t& crlf2_endof_message = this->crlf2_endof_message();
        crlf2_endof_message.assign(to);
        return crlf2_endof_message;
    }
    virtual string_t& crlf2_endof_message() const {
        return (string_t&)crlf2_endof_message_;
    }
    ///////////////////////////////////////////////////////////////////////
    /// ...crlf_endof_message
    virtual string_t& set_crlf_endof_message(const string_t& to) {
        string_t& crlf_endof_message = this->crlf_endof_message();
        crlf_endof_message.assign(to);
        return crlf_endof_message;
    }
    virtual string_t& set_crlf_endof_message(const char_t* to, size_t length) {
        string_t& crlf_endof_message = this->crlf_endof_message();
        crlf_endof_message.assign(to, length);
        return crlf_endof_message;
    }
    virtual string_t& set_crlf_endof_message(const char_t* to) {
        string_t& crlf_endof_message = this->crlf_endof_message();
        crlf_endof_message.assign(to);
        return crlf_endof_message;
    }
    virtual string_t& crlf_endof_message() const {
        return (string_t&)crlf_endof_message_;
    }
    ///////////////////////////////////////////////////////////////////////
    /// ...cr_endof_message
    virtual string_t& set_cr_endof_message(const string_t& to) {
        string_t& cr_endof_message = this->cr_endof_message();
        cr_endof_message.assign(to);
        return cr_endof_message;
    }
    virtual string_t& set_cr_endof_message(const char_t* to, size_t length) {
        string_t& cr_endof_message = this->cr_endof_message();
        cr_endof_message.assign(to, length);
        return cr_endof_message;
    }
    virtual string_t& set_cr_endof_message(const char_t* to) {
        string_t& cr_endof_message = this->cr_endof_message();
        cr_endof_message.assign(to);
        return cr_endof_message;
    }
    virtual string_t& cr_endof_message() const {
        return (string_t&)cr_endof_message_;
    }
    ///////////////////////////////////////////////////////////////////////
    /// ...lf_endof_message
    virtual string_t& set_lf_endof_message(const string_t& to) {
        string_t& lf_endof_message = this->lf_endof_message();
        lf_endof_message.assign(to);
        return lf_endof_message;
    }
    virtual string_t& set_lf_endof_message(const char_t* to, size_t length) {
        string_t& lf_endof_message = this->lf_endof_message();
        lf_endof_message.assign(to, length);
        return lf_endof_message;
    }
    virtual string_t& set_lf_endof_message(const char_t* to) {
        string_t& lf_endof_message = this->lf_endof_message();
        lf_endof_message.assign(to);
        return lf_endof_message;
    }
    virtual string_t& lf_endof_message() const {
        return (string_t&)lf_endof_message_;
    }
    /// ...
    /// ...endof_message
    ///////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    /// ...known...
    /// ...
    /// ...known_request
    virtual string_t& set_known_request(const string_t& to) {
        string_t& known_request = this->known_request();
        known_request.assign(to);
        return known_request;
    }
    virtual string_t& set_known_request(const char_t* to) {
        string_t& known_request = this->known_request();
        known_request.assign(to);
        return known_request;
    }
    virtual string_t& set_known_request(const char_t* to, size_t length) {
        string_t& known_request = this->known_request();
        known_request.assign(to, length);
        return known_request;
    }
    virtual string_t& known_request() const {
        return (string_t&)known_request_;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...known_response
    virtual string_t& set_known_response(const string_t& to) {
        string_t& known_response = this->known_response();
        known_response.assign(to);
        return known_response;
    }
    virtual string_t& set_known_response(const char_t* to, size_t length) {
        string_t& known_response = this->known_response();
        known_response.assign(to, length);
        return known_response;
    }
    virtual string_t& set_known_response(const char_t* to) {
        string_t& known_response = this->known_response();
        known_response.assign(to);
        return known_response;
    }
    virtual string_t& known_response() const {
        return (string_t&)known_response_;
    }
    /// ...
    /// ...known...
    ///////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    /// ...unknown...
    /// ...
    /// ...unknown_request
    virtual string_t& set_unknown_request(const string_t& to) {
        string_t& unknown_request = this->unknown_request();
        unknown_request.assign(to);
        return unknown_request;
    }
    virtual string_t& set_unknown_request(const char_t* to) {
        string_t& unknown_request = this->unknown_request();
        unknown_request.assign(to);
        return unknown_request;
    }
    virtual string_t& set_unknown_request(const char_t* to, size_t length) {
        string_t& unknown_request = this->unknown_request();
        unknown_request.assign(to, length);
        return unknown_request;
    }
    virtual string_t& unknown_request() const {
        return (string_t&)unknown_request_;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...unknown_response
    virtual string_t& set_unknown_response(const string_t& to) {
        string_t& unknown_response = this->unknown_response();
        unknown_response.assign(to);
        return unknown_response;
    }
    virtual string_t& set_unknown_response(const char_t* to, size_t length) {
        string_t& unknown_response = this->unknown_response();
        unknown_response.assign(to, length);
        return unknown_response;
    }
    virtual string_t& set_unknown_response(const char_t* to) {
        string_t& unknown_response = this->unknown_response();
        unknown_response.assign(to);
        return unknown_response;
    }
    virtual string_t& unknown_response() const {
        return (string_t&)unknown_response_;
    }
    /// ...
    /// ...unknown...
    ///////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    /// ...request
    virtual string_t& set_request(const string_t& to) {
        string_t& request = this->request();
        request.assign(to);
        return request;
    }
    virtual string_t& set_request(const char_t* to) {
        string_t& request = this->request();
        request.assign(to);
        return request;
    }
    virtual string_t& set_request(const char_t* to, size_t length) {
        string_t& request = this->request();
        request.assign(to, length);
        return request;
    }
    virtual string_t& request() const {
        return (string_t&)request_;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...response
    virtual string_t& set_response(const string_t& to) {
        string_t& response = this->response();
        response.assign(to);
        return response;
    }
    virtual string_t& set_response(const char_t* to, size_t length) {
        string_t& response = this->response();
        response.assign(to, length);
        return response;
    }
    virtual string_t& set_response(const char_t* to) {
        string_t& response = this->response();
        response.assign(to);
        return response;
    }
    virtual string_t& response() const {
        return (string_t&)response_;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...restart
    virtual bool& set_restart(const bool& to) {
        bool& restart = this->restart();
        restart = to;
        return restart;
    }
    virtual bool& restart_set(const bool& to) {
        bool& restart = this->restart();
        return restart;
    }
    virtual const bool& get_restart() const {
        return this->restart();
    }
    virtual bool& restart() const {
        bool& restart = (bool&)restart_;
        return restart;
    }
    ///////////////////////////////////////////////////////////////////////
    /// ...start
    virtual bool& set_start(const bool& to) {
        bool& start = this->start();
        start = to;
        return start;
    }
    virtual bool& start_set(const bool& to) {
        bool& start = this->start();
        return start;
    }
    virtual const bool& get_start() const {
        return this->start();
    }
    virtual bool& start() const {
        bool& start = (bool&)start_;
        return start;
    }
    ///////////////////////////////////////////////////////////////////////
    /// ...stop
    virtual bool& set_stop(const bool& to) {
        bool& stop = this->stop();
        stop = to;
        return stop;
    }
    virtual bool& stop_set(const bool& to) {
        bool& stop = this->stop();
        return stop;
    }
    virtual const bool& get_stop() const {
        return this->stop();
    }
    virtual bool& stop() const {
        bool& stop = (bool&)stop_;
        return stop;
    }

protected:
    bool restart_, start_, stop_;
    string_t request_, response_, 
             known_request_, known_response_,
             unknown_request_, unknown_response_,
             crlf2_endof_message_, crlf_endof_message_, 
             cr_endof_message_, lf_endof_message_;
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace base 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_BASE_MAIN_OPT_HPP
