/**
 *
 *                  __                   .__         .__            ____
 *  ________      _/  |_ _______ _____   |__|  ____  |__|  ____    / ___\
 *  \___   /______\   __\\_  __ \\__  \  |  | /    \ |  | /    \  / /_/  >
 *   /    //_____/ |  |   |  | \/ / __ \_|  ||   |  \|  ||   |  \ \___  /
 *  /_____ \       |__|   |__|   (____  /|__||___|  /|__||___|  //_____/
 *        \/                          \/          \/          \/
 *
 * HOW TO USE THIS HEADER FILE:
 * - Login to www.z-training.net using your browser
 * - In your solution include this file ("zi.h"). DO NOT RENAME THE FILE!
 * - In your main function make the first line ZGRADE(username, taskId);
 *   where username is your z-training username (without quotes!) and
 *   taskId is the id of the task you are solving
 * - Alternatively put ZGRADED(username, taskId) anywhere in the global
 *   scope after the #include "zi.h"
 * - Compile and RUN!
 *
 * The submission for the task "Sum of Two Numbers" would look like this:
 *
 *    #include <iostream>
 *    #include "zi.h"
 *
 *    int main () {
 *      ZGRADE(admin, 5000000001);
 *      int a, b;
 *      std::cin >> a >> b;
 *      std::cout << (a+b);
 *      return 0;
 *    }
 *
 * Or like this:
 *
 *    #include <iostream>
 *    #include "zi.h"
 *    ZGRADED(admin, 5000000001);
 *
 *    int main () {
 *      int a, b;
 *      std::cin >> a >> b;
 *      std::cout << (a+b);
 *      return 0;
 *    }
 *
 * Linux (gcc):       g++ sum.cpp -o sum.bin; ./sum.bin
 * MacOS (gcc):       g++ sum.cpp -o sum.bin; ./sum.bin
 * Windows (cygwin):  g++ sum.cpp -o sum.bin; ./sum.bin
 *
 * Windows (MinGW):   g++ sum.cpp -lws2_32 -o sum.exe
 *                    sum.exe
 *
 * Windows (Dev C++): In Tools/Compiler options check the field
 *                    `Add these commands to the linker command line`
 *                    and in the textbox below add "-lws2_32" (no quotes)
 *                    press "F9" and voala!
 *
 * Windows (VS):      Not tested, but should work out of the box.
 *
 *
 */

#ifndef _ZI_REMOTE_GRADE_H_
#define _ZI_REMOTE_GRADE_H_

#include <fstream>
#include <iostream>
#include <string>

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#if (defined(WIN32) || defined(__WIN32__) || defined(__WIN32)) &&       \
  !(defined(__CYGWIN32__) || defined(__CYGWIN__))
# define ZWINDOWS
#endif

#ifdef ZWINDOWS
# include <windows.h>
# include <winsock2.h>
# include <ws2tcpip.h>
# define EAFNOSUPPORT   WSAEAFNOSUPPORT
# define MSG_NOSIGNAL 0
#else
# include <arpa/inet.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <netdb.h>
# include <signal.h>
# include <unistd.h>
#endif

#ifdef ZWINDOWS
# define WSINIT                                 \
  do {                                          \
    WSADATA wsaData;                            \
    WSAStartup(2, &wsaData);                    \
  } while (0);
#else
# define WSINIT do {} while(0)
#endif

#ifdef ZWINDOWS
int inet_pton (int af, const char *src, void *dst) {
  struct addrinfo ainfo;
  struct addrinfo *res = NULL;

  memset(&ainfo, 0, sizeof(ainfo));
  ainfo.ai_family = af;
  ainfo.ai_socktype = SOCK_STREAM;
  ainfo.ai_protocol = IPPROTO_TCP;

  if (getaddrinfo(src, "80", &ainfo, &res))
    return -1;

  const void *data;
  size_t len;

  switch (af) {
  case AF_INET:
    data = &((const struct sockaddr_in *)res->ai_addr)->sin_addr;
    len = sizeof (struct in_addr);
    break;
  }
  memcpy (dst, data, len);
  return 0;
}
#endif

#define GETMYCONTENT(_var_)                     \
  do {                                          \
    WSINIT;                                     \
    char buf[65536];                            \
    std::ifstream fin(__FILE__);                \
    fin.get(buf, 65536, EOF);                   \
    _var_ = std::string(buf, fin.gcount());     \
  } while(false);

#define ZGRADED(_user_, _task_)                                 \
  class zSolution_ ## _user_ ## _task_ {                        \
  public:                                                       \
  std::string getCode() const {                                 \
    char buf[65536];                                            \
    std::ifstream fin(__FILE__);                                \
    fin.get(buf, 65536, EOF);                                   \
    return std::string(buf, fin.gcount());                      \
  }                                                             \
  const char* getUser() const { return #_user_; }               \
  const char* getTask() const { return #_task_; }               \
  };                                                            \
  static zi::zRemoteSignup<zSolution_ ## _user_ ## _task_ >     \
  zSignup_ ## _user_ ## _task_;

#define ZGRADE(_user_, _task_)                  \
  do {                                          \
    std::string s;                              \
    GETMYCONTENT(s);                            \
    std::cout << #_user_ << " :: "              \
              << #_task_ << std::endl;          \
    zi::postSubmission(#_user_, #_task_, s);    \
    return 0;                                   \
  } while(false)

namespace zi {

std::string char2hex(char dec) {
  char buff[2];
  sprintf(buff, "%02x", dec);
  return std::string(buff);
}

std::string urlencode(const std::string &c) {
  std::string escaped;
  int max = c.length();
  for (int i=0; i < max; i++) {
    unsigned char d = (unsigned char)c[i];
    if ( ('0' <= d && d <= '9') ||
         ('a' <= d && d <= 'z') ||
         ('A' <= d && d <= 'Z') ||
         (d == '~' || d == '!' || d == '*') ||
         (d == '(' || d == ')' || d == '\'') )
      escaped.append((char*)(&d), 1);
    else
      escaped.append("%" + char2hex(d));
  }
  return escaped;
}

const int MAXRECV = 500;

class Socket {
public:
  Socket(): m_sock ( -1 ) { memset(&m_addr, 0, sizeof(m_addr)); }
  virtual ~Socket() { if (is_valid()) ::close(m_sock); }
  bool create() {
    m_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (!is_valid()) return false;
    int on = 1;
    return (setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR,
                       (const char*) &on, sizeof(on)) != -1 );
  }

  bool bind (const int port) {
    if (!is_valid()) return false;
    m_addr.sin_family = AF_INET;
    m_addr.sin_addr.s_addr = INADDR_ANY;
    m_addr.sin_port = htons(port);
    return (::bind(m_sock, (struct sockaddr*) &m_addr, sizeof(m_addr)) != -1);
  }

  bool connect(const std::string host, const int port) {
    if (!is_valid()) return false;
    m_addr.sin_family = AF_INET;
    m_addr.sin_port = htons(port);
    int status = inet_pton(AF_INET, host.c_str(), &m_addr.sin_addr);
    if (errno == EAFNOSUPPORT) return false;
    status = ::connect(m_sock, (sockaddr*)&m_addr, sizeof(m_addr));
    return (status == 0);
  }

  bool send(const std::string s) const {
    return (::send(m_sock, s.c_str(), s.size(), MSG_NOSIGNAL) != -1);
  }

  int recv(std::string& s) const {
    char buf [MAXRECV + 1];
    s = ""; memset(buf, 0, MAXRECV + 1);
    int status = ::recv(m_sock, buf, MAXRECV, 0);
    if (status == -1) {
      std::cout << "status == -1   errno == " << errno << "  in Socket::recv\n";
      return 0;
    } else if (status == 0) {
      return 0;
    } else {
      s = buf;
      return status;
    }
  }

  bool is_valid() const { return m_sock != -1; }

private:
  int m_sock;
  sockaddr_in m_addr;
};

class SocketException {
public:
  SocketException ( std::string s ) : m_s ( s ) {};
  ~SocketException (){};
  std::string description() { return m_s; }
private:
  std::string m_s;
};

class ClientSocket : private Socket {
public:
  ClientSocket (std::string host, int port) {
    if (!Socket::create()) {
      throw SocketException ( "Could not create client socket." );
    }
    if (!Socket::connect (host, port))  {
      throw SocketException ( "Could not bind to port." );
    }
  }
  virtual ~ClientSocket(){};
  const ClientSocket& operator << ( const std::string& s) const {
    if ( ! Socket::send ( s ) ) {
      throw SocketException ( "Could not write to socket." );
    }
    return *this;
  }
  const ClientSocket& operator >> ( std::string& s) const {
    if ( ! Socket::recv ( s ) ) {
      throw SocketException ( "Could not read from socket." );
    }
    return *this;
  }

};

void postSubmission(const std::string& username,
                    const std::string& taskId,
                    const std::string& code)
{
  std::string postData = "&username=" + username +
    "&problemId=" + taskId + "&langId=65539" +
    "&code=" + urlencode(code);

  char command[128000];
  sprintf(command,
          "POST /api.php HTTP/1.1\r\n"
          "Connection: close\r\n"
          "Host: www.z-trening.com\r\n"
          "Content-Length: %d\r\n"
          "Content-Type: application/x-www-form-urlencoded\r\n\r\n\0",
          postData.size());
  try {
    std::string result;
    ClientSocket client_socket("18.97.4.143", 80);
    std::string reply;
    try  {
      client_socket << std::string(command) + postData + "\r\n";
      while (1) {
        client_socket >> reply;
        result += reply;
      }
    }
    catch ( SocketException& ) {}
    size_t rpos;
    rpos = result.find("\r\n\r\n");
    if (rpos != std::string::npos) {
      std::cout << result.substr(rpos+2);
    }
  } catch ( SocketException& e ) {
    std::cout << "Exception was caught:" << e.description() << "\n";
  }
}

template<class T>
struct zRemoteSignup {
  zRemoteSignup() {
    WSINIT;
    T t;
    std::string s;
    GETMYCONTENT(s);
    std::cout << t.getUser() << " :: "
              << t.getTask() << std::endl;
    postSubmission(std::string(t.getUser()),
                   std::string(t.getTask()),
                   t.getCode());
    exit(0);
  }
};

};

#endif
