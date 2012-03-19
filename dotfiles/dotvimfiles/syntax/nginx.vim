" Vim syntax file
" Language:     Nginx configuration (nginx.conf)
" Maintainer:   Evan Miller
" Last Change:  2007 May 02
" Notes: This is a bit patchy.

if exists("b:current_syntax")
    finish
end

setlocal iskeyword+=.
setlocal iskeyword+=/
setlocal iskeyword+=:

" basics
syn match ngxStringVariable "\$\w\w*" contained
syn region ngxString start=+"+ end=+"+ skip=+\\\\\|\\"+ contains=ngxStringVariable oneline
syn region ngxString start=+'+ end=+'+ skip=+\\\\\|\\'+ contains=ngxStringVariable oneline

" Main
syn keyword ngxDirective daemon debug_points error_log lock_file master_process pid ssl_engine timer_resolution user group worker_cpu_affinity worker_priority worker_processes worker_rlimit_core worker_rlimit_nofile worker_rlimit_sigpending working_directory
syn keyword ngxDirectiveImportant include
syn keyword ngxBlockDirective http events contained
syn keyword ngxBlockDirective server contained

"Events
syn keyword ngxDirective accept_mutex accept_mutex_delay debug_connection devpoll_changes devpoll_events epoll_events kqueue_changes kqueue_events multi_accept rtsig_signo rtsig_overflow_events rtsig_overflow_test rtsig_overflow_threshold use worker_connections

" HTTP core
syn keyword ngxDirective alias client_body_in_file_only client_body_buffer_size client_body_temp_path client_body_timeout client_header_buffer_size client_header_timeout client_max_body_size default_type keepalive_timeout large_client_header_buffers limit_rate msie_padding msie_refresh optimize_server_names port_in_redirect recursive_error_pages satisfy_any send_timeout sendfile server_names_hash_max_size server_names_hash_bucket_size tcp_nodelay tcp_nopush internal
syn keyword ngxDirective output_buffers postpone_output send_lowat connections
syn keyword ngxDirectiveImportant root server server_name listen
syn keyword ngxDirectiveError error_page
syn keyword ngxBlockDirective location limit_except types contained

" Access
syn keyword ngxDirective allow deny

" Auth
syn keyword ngxDirective auth_basic auth_basic_user_file

" Auto-index
syn keyword ngxDirective autoindex
syn keyword ngxDirective autoindex_exact_size
syn keyword ngxDirective autoindex_localtime

" DAV
syn keyword ngxDirective dav_access dav_methods create_full_put_path 

" FastCGI 
syn keyword ngxDirective fastcgi_index fastcgi_hide_header fastcgi_intercept_errors fastcgi_param fastcgi_pass_header fastcgi_redirect_errors
syn keyword ngxDirectiveImportant fastcgi_pass

" gzip
syn keyword ngxDirective gzip gzip_buffers gzip_comp_level gzip_min_length gzip_http_version gzip_proxied gzip_types 

" header
syn keyword ngxDirective add_header 
syn keyword ngxDirective expires 

" auto-index
syn keyword ngxDirective index

" log
syn keyword ngxDirective access_log log_format

" proxy 
syn keyword ngxDirective proxy_buffer_size proxy_buffering proxy_buffers proxy_connect_timeout proxy_hide_header proxy_intercept_errors proxy_method proxy_next_upstream proxy_pass_header proxy_read_timeout proxy_redirect_errors proxy_send_timeout proxy_set_header proxy_temp_path proxy_temp_file_write_size proxy_busy_buffers_size proxy_send_lowat
syn keyword ngxDirectiveImportant proxy_pass proxy_redirect

" rewrite
syn keyword ngxDirectiveControl break return set uninitialized_variable_warn rewrite
syn keyword ngxDirective uninitialized_variable_warn
syn keyword ngxBlockDirective if contained

" SSL 
syn keyword ngxDirective ssl ssl_certificate ssl_certificate_key ssl_client_certificate ssl_ciphers ssl_prefer_server_ciphers ssl_protocols ssl_verify_client ssl_verify_depth ssl_session_cache ssl_session_timeout

" Upstream
syn keyword ngxDirective ip_hash server
syn keyword ngxBlockDirective upstream contained

" Addition
syn keyword ngxDirectiveImportant add_before_body add_after_body

" Charset
syn keyword ngxDirective charset charset_map override_charset source_charset

" empty gif
syn keyword ngxDirective empty_gif

" geo
syn keyword ngxBlockDirective geo

" map
syn keyword ngxBlockDirective map
syn keyword ngxDirective map_hash_max_size map_hash_bucket_size

" realip
syn keyword ngxDirective set_real_ip_from real_ip_header

" referer
syn keyword ngxDirective valid_referers

" ssi
syn keyword ngxDirective ssi

" user id
syn keyword ngxDirective userid userid_domain userid_expires userid_name userid_p3p userid_path userid_service

" sub filter
syn keyword ngxDirective sub_filter sub_filter_once sub_filter_types

" perl
syn keyword ngxDirective perl_modules perl_require perl_set

" limit zone
syn keyword ngxDirective limit_zone limit_conn

" memcache
syn keyword ngxDirective memcached_connect_timeout memcached_send_timeout memcached_read_timeout memcached_buffer_size memcached_next_upstream 
syn keyword ngxDirectiveImportant memcached_pass

" stub
syn keyword ngxDirective stub_status

" flv
syn keyword ngxDirective flv

" browser 
syn keyword ngxDirective ancient_browser ancient_browser_value modern_browser modern_browser_value

syn region ngxStartBlock start=+^+ end=+{+ contains=ngxBlockDirective,ngxContextVariable oneline

syn match ngxContextVariable "\$\w\w*" contained
syn match ngxComment " *#.*$"
syn match ngxVariable "\$\w\w*"

hi link ngxBlockDirective Statement
hi link ngxStartBlock Normal

hi link ngxStringVariable Special
hi link ngxDirectiveControl Special
hi link ngxComment Comment
hi link ngxString String
hi link ngxDirective Identifier
hi link ngxDirectiveImportant Type
hi link ngxVariable Identifier
hi link ngxContextVariable Identifier
hi link ngxDirectiveError Constant

let b:current_syntax = "nginx"
