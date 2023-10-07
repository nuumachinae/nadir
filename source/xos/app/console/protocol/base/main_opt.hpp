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
///   Date: 8/18/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPT_HPP

#include "xos/app/console/base/main.hpp"

#define XOS_APP_CONSOLE_PROTOCOL_DEFAULT_REQUEST \
    "GET / HTTP/1.0\r\n" \
    "Content-Type:text/plain\r\n" \
    "Content-Length:7\r\n\r\n" \
    "hello\r\n"

#define XOS_APP_CONSOLE_PROTOCOL_DEFAULT_RESPONSE \
    "HTTP/1.0 200 Ok\r\n" \
    "Content-Type:text/plain\r\n" \
    "Content-Length:7\r\n\r\n" \
    "hello\r\n"

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPTIONS_CHARS_EXTEND \

#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_ARGS 0
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace base {

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
    main_optt()
    : run_(0),
      
      hello_request_("hello"),
      hello_response_(hello_request_),

      restart_request_("restart"),
      restart_response_(restart_request_),

      start_request_("start"),
      start_response_(start_request_),

      stop_request_("stop"),
      stop_response_(stop_request_),
      
      default_request_(XOS_APP_CONSOLE_PROTOCOL_DEFAULT_REQUEST),
      default_response_(XOS_APP_CONSOLE_PROTOCOL_DEFAULT_RESPONSE),
    
      request_(default_request_), 
      response_(default_response_)/*,

      crlf2_endof_message_("\r\n\r\n"), 
      crlf_endof_message_("\r\n"), 
      cr_endof_message_("\r"), 
      lf_endof_message_("\n")*/ {
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

    typedef typename extends::file_reader_t file_reader_t;

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
    /// default_prepare_response_to_request_run
    virtual int default_prepare_response_to_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0, unequal = 0;
        const string_t& hello_request = this->hello_request();
        LOGGER_IS_LOGGED_INFO("!(unequal = hello_request.compare(request))...");
        if (!(unequal = hello_request.compare(request))) {
            LOGGER_IS_LOGGED_INFO("...!(unequal = hello_request.compare(request))");

            LOGGER_IS_LOGGED_INFO("!(err = all_prepare_response_to_hello_request_run(response, request, argc, argv, env))...");
            if (!(err = all_prepare_response_to_hello_request_run(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_prepare_response_to_hello_request_run(response, request, argc, argv, env))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_prepare_response_to_hello_request_run(response, request, argc, argv, env))");
            }
            return err;
        } else {
        }
        const string_t& restart_request = this->restart_request();
        LOGGER_IS_LOGGED_INFO("!(unequal = restart_request.compare(request))...");
        if (!(unequal = restart_request.compare(request))) {
            LOGGER_IS_LOGGED_INFO("...!(unequal = restart_request.compare(request))");

            LOGGER_IS_LOGGED_INFO("!(err = all_prepare_response_to_restart_request_run(response, request, argc, argv, env))...");
            if (!(err = all_prepare_response_to_restart_request_run(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_prepare_response_to_restart_request_run(response, request, argc, argv, env))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_prepare_response_to_restart_request_run(response, request, argc, argv, env))");
            }
            return err;
        } else {
        }
        const string_t& start_request = this->start_request();
        LOGGER_IS_LOGGED_INFO("!(unequal = start_request.compare(request))...");
        if (!(unequal = start_request.compare(request))) {
            LOGGER_IS_LOGGED_INFO("...!(unequal = start_request.compare(request))");

            LOGGER_IS_LOGGED_INFO("!(err = all_prepare_response_to_start_request_run(response, request, argc, argv, env))...");
            if (!(err = all_prepare_response_to_start_request_run(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_prepare_response_to_start_request_run(response, request, argc, argv, env))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_prepare_response_to_start_request_run(response, request, argc, argv, env))");
            }
            return err;
        } else {
        }
        const string_t& stop_request = this->stop_request();
        LOGGER_IS_LOGGED_INFO("!(unequal = stop_request.compare(request))...");
        if (!(unequal = stop_request.compare(request))) {
            LOGGER_IS_LOGGED_INFO("...!(unequal = stop_request.compare(request))");

            LOGGER_IS_LOGGED_INFO("!(err = all_prepare_response_to_stop_request_run(response, request, argc, argv, env))...");
            if (!(err = all_prepare_response_to_stop_request_run(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_prepare_response_to_stop_request_run(response, request, argc, argv, env))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_prepare_response_to_stop_request_run(response, request, argc, argv, env))");
            }
            return err;
        } else {
        }
        LOGGER_IS_LOGGED_INFO("!(err = extends::default_prepare_response_to_unknown_request_run(response, request, argc, argv, env)))...");
        if (!(err = extends::default_prepare_response_to_request_run(response, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = extends::default_prepare_response_to_unknown_request_run(response, request, argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = extends::default_prepare_response_to_unknown_request_run(response, request, argc, argv, env)))");
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_hello_request_run
    int (derives::*prepare_response_to_hello_request_run_)(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env);
    virtual int prepare_response_to_hello_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_response_to_hello_request_run_) {
            err = (this->*prepare_response_to_hello_request_run_)(response, request, argc, argv, env);
        } else {
            err = default_prepare_response_to_hello_request_run(response, request, argc, argv, env);
        }
        return err;
    }
    virtual int default_prepare_response_to_hello_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& hello_response = this->hello_response();
        response.assign(hello_response);
        return err;
    }
    virtual int before_prepare_response_to_hello_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_hello_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_hello_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_to_hello_request_run(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_to_hello_request_run(response, request, argc, argv, env);
            if ((err2 = after_prepare_response_to_hello_request_run(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_restart_request_run
    int (derives::*prepare_response_to_restart_request_run_)(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env);
    virtual int prepare_response_to_restart_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_response_to_restart_request_run_) {
            err = (this->*prepare_response_to_restart_request_run_)(response, request, argc, argv, env);
        } else {
            err = default_prepare_response_to_restart_request_run(response, request, argc, argv, env);
        }
        return err;
    }
    virtual int default_prepare_response_to_restart_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& restart_response = this->restart_response();
        bool restart = this->set_restart(true);
        this->restart_set(restart);
        response.assign(restart_response);
        return err;
    }
    virtual int before_prepare_response_to_restart_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_restart_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_restart_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_to_restart_request_run(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_to_restart_request_run(response, request, argc, argv, env);
            if ((err2 = after_prepare_response_to_restart_request_run(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_start_request_run
    int (derives::*prepare_response_to_start_request_run_)(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env);
    virtual int prepare_response_to_start_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_response_to_start_request_run_) {
            err = (this->*prepare_response_to_start_request_run_)(response, request, argc, argv, env);
        } else {
            err = default_prepare_response_to_start_request_run(response, request, argc, argv, env);
        }
        return err;
    }
    virtual int default_prepare_response_to_start_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& start_response = this->start_response();
        bool start = this->set_start(true);
        this->start_set(start);
        response.assign(start_response);
        return err;
    }
    virtual int before_prepare_response_to_start_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_start_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_start_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_to_start_request_run(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_to_start_request_run(response, request, argc, argv, env);
            if ((err2 = after_prepare_response_to_start_request_run(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_stop_request_run
    int (derives::*prepare_response_to_stop_request_run_)(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env);
    virtual int prepare_response_to_stop_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_response_to_stop_request_run_) {
            err = (this->*prepare_response_to_stop_request_run_)(response, request, argc, argv, env);
        } else {
            err = default_prepare_response_to_stop_request_run(response, request, argc, argv, env);
        }
        return err;
    }
    virtual int default_prepare_response_to_stop_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& stop_response = this->stop_response();
        bool stop = this->set_stop(true);
        this->stop_set(stop);
        response.assign(stop_response);
        return err;
    }
    virtual int before_prepare_response_to_stop_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_stop_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_stop_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_to_stop_request_run(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_to_stop_request_run(response, request, argc, argv, env);
            if ((err2 = after_prepare_response_to_stop_request_run(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

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
        static const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...hello_request
    virtual string_t& set_hello_request(const string_t& to) {
        string_t& hello_request = this->hello_request();
        hello_request.assign(to);
        return hello_request;
    }
    virtual string_t& set_hello_request(const char_t* to) {
        string_t& hello_request = this->hello_request();
        hello_request.assign(to);
        return hello_request;
    }
    virtual string_t& set_hello_request(const char_t* to, size_t length) {
        string_t& hello_request = this->hello_request();
        hello_request.assign(to, length);
        return hello_request;
    }
    virtual string_t& hello_request() const {
        return (string_t&)hello_request_;
    }
    ///////////////////////////////////////////////////////////////////////
    /// ...hello_response
    virtual string_t& set_hello_response(const string_t& to) {
        string_t& hello_response = this->hello_response();
        hello_response.assign(to);
        return hello_response;
    }
    virtual string_t& set_hello_response(const char_t* to, size_t length) {
        string_t& hello_response = this->hello_response();
        hello_response.assign(to, length);
        return hello_response;
    }
    virtual string_t& set_hello_response(const char_t* to) {
        string_t& hello_response = this->hello_response();
        hello_response.assign(to);
        return hello_response;
    }
    virtual string_t& hello_response() const {
        return (string_t&)hello_response_;
    }
    
    ///////////////////////////////////////////////////////////////////////
    /// ...restart_request
    virtual string_t& set_restart_request(const string_t& to) {
        string_t& restart_request = this->restart_request();
        restart_request.assign(to);
        return restart_request;
    }
    virtual string_t& set_restart_request(const char_t* to) {
        string_t& restart_request = this->restart_request();
        restart_request.assign(to);
        return restart_request;
    }
    virtual string_t& set_restart_request(const char_t* to, size_t length) {
        string_t& restart_request = this->restart_request();
        restart_request.assign(to, length);
        return restart_request;
    }
    virtual string_t& restart_request() const {
        return (string_t&)restart_request_;
    }
    ///////////////////////////////////////////////////////////////////////
    /// ...restart_response
    virtual string_t& set_restart_response(const string_t& to) {
        string_t& restart_response = this->restart_response();
        restart_response.assign(to);
        return restart_response;
    }
    virtual string_t& set_restart_response(const char_t* to, size_t length) {
        string_t& restart_response = this->restart_response();
        restart_response.assign(to, length);
        return restart_response;
    }
    virtual string_t& set_restart_response(const char_t* to) {
        string_t& restart_response = this->restart_response();
        restart_response.assign(to);
        return restart_response;
    }
    virtual string_t& restart_response() const {
        return (string_t&)restart_response_;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...start_request
    virtual string_t& set_start_request(const string_t& to) {
        string_t& start_request = this->start_request();
        start_request.assign(to);
        return start_request;
    }
    virtual string_t& set_start_request(const char_t* to) {
        string_t& start_request = this->start_request();
        start_request.assign(to);
        return start_request;
    }
    virtual string_t& set_start_request(const char_t* to, size_t length) {
        string_t& start_request = this->start_request();
        start_request.assign(to, length);
        return start_request;
    }
    virtual string_t& start_request() const {
        return (string_t&)start_request_;
    }
    ///////////////////////////////////////////////////////////////////////
    /// ...start_response
    virtual string_t& set_start_response(const string_t& to) {
        string_t& start_response = this->start_response();
        start_response.assign(to);
        return start_response;
    }
    virtual string_t& set_start_response(const char_t* to, size_t length) {
        string_t& start_response = this->start_response();
        start_response.assign(to, length);
        return start_response;
    }
    virtual string_t& set_start_response(const char_t* to) {
        string_t& start_response = this->start_response();
        start_response.assign(to);
        return start_response;
    }
    virtual string_t& start_response() const {
        return (string_t&)start_response_;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...stop_request
    virtual string_t& set_stop_request(const string_t& to) {
        string_t& stop_request = this->stop_request();
        stop_request.assign(to);
        return stop_request;
    }
    virtual string_t& set_stop_request(const char_t* to) {
        string_t& stop_request = this->stop_request();
        stop_request.assign(to);
        return stop_request;
    }
    virtual string_t& set_stop_request(const char_t* to, size_t length) {
        string_t& stop_request = this->stop_request();
        stop_request.assign(to, length);
        return stop_request;
    }
    virtual string_t& stop_request() const {
        return (string_t&)stop_request_;
    }
    ///////////////////////////////////////////////////////////////////////
    /// ...stop_response
    virtual string_t& set_stop_response(const string_t& to) {
        string_t& stop_response = this->stop_response();
        stop_response.assign(to);
        return stop_response;
    }
    virtual string_t& set_stop_response(const char_t* to, size_t length) {
        string_t& stop_response = this->stop_response();
        stop_response.assign(to, length);
        return stop_response;
    }
    virtual string_t& set_stop_response(const char_t* to) {
        string_t& stop_response = this->stop_response();
        stop_response.assign(to);
        return stop_response;
    }
    virtual string_t& stop_response() const {
        return (string_t&)stop_response_;
    }

    ///////////////////////////////////////////////////////////////////////
    /// ...default_request
    virtual string_t& set_default_request(const string_t& to) {
        string_t& default_request = this->default_request();
        default_request.assign(to);
        return default_request;
    }
    virtual string_t& set_default_request(const char_t* to) {
        string_t& default_request = this->default_request();
        default_request.assign(to);
        return default_request;
    }
    virtual string_t& set_default_request(const char_t* to, size_t length) {
        string_t& default_request = this->default_request();
        default_request.assign(to, length);
        return default_request;
    }
    virtual string_t& default_request() const {
        return (string_t&)default_request_;
    }
    ///////////////////////////////////////////////////////////////////////
    /// ...default_response
    virtual string_t& set_default_response(const string_t& to) {
        string_t& default_response = this->default_response();
        default_response.assign(to);
        return default_response;
    }
    virtual string_t& set_default_response(const char_t* to, size_t length) {
        string_t& default_response = this->default_response();
        default_response.assign(to, length);
        return default_response;
    }
    virtual string_t& set_default_response(const char_t* to) {
        string_t& default_response = this->default_response();
        default_response.assign(to);
        return default_response;
    }
    virtual string_t& default_response() const {
        return (string_t&)default_response_;
    }

    /*
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
    */
    
    ///////////////////////////////////////////////////////////////////////
    /// ...request
    virtual string_t& request() const {
        return (string_t&)request_;
    }
    ///////////////////////////////////////////////////////////////////////
    /// ...response
    virtual string_t& response() const {
        return (string_t&)response_;
    }

protected:
    string_t hello_request_, hello_response_, 
             restart_request_, restart_response_, 
             start_request_, start_response_, 
             stop_request_, stop_response_, 
             default_request_, default_response_,
             request_, response_/*,
             crlf2_endof_message_, crlf_endof_message_, 
             cr_endof_message_, lf_endof_message_*/;
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace base 
} /// namespace protocol 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPT_HPP
