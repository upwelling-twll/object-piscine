#ifndef DEBUG_HPP
# define DEBUG_HPP

# include <iostream>
# include <string>

/* Colors */

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\e[0;36m"
#define GREY    "\033[90m"
#define PINK    "\033[95m"


/* Constructor logs */

#ifdef DEBUG_CTOR
# define LOG_CTOR(msg) \
    std::cout << GREEN << "[CONSTR] " << msg << RESET << std::endl
#else
# define LOG_CTOR(msg)
#endif

/* Destructor logs */

#ifdef DEBUG_DTOR
# define LOG_DTOR(msg) \
    std::cout << RED << "[DESTRUC] " << msg  << RESET << std::endl
#else
# define LOG_DTOR(msg)
#endif

/* Actions */

#ifdef DEBUG_ACTION
# define LOG_ACTION(msg) \
    std::cout << CYAN << "[ACTION] " << msg  << RESET << std::endl
#else
# define LOG_ACTION(msg)
#endif

/* Object printing */

#ifdef DEBUG_INFO
# define LOG_INFO(obj) \
    std::cout << YELLOW << "[INFO] " << obj << RESET << std::endl
#else
# define LOG_INFO(obj)
#endif

#ifdef DEBUG_WARNING
# define LOG_WARNING(obj) \
    std::cout << PINK << "[WARNING] " << obj << RESET << std::endl
#else
# define LOG_WARNING(obj)
#endif

#ifdef DEBUG_DBUG
# define LOG_DBUG(msg) \
    std::cout << GREY << "[DEBUG] " << msg  << RESET << std::endl
#else
# define LOG_DBUG(msg)
#endif

#endif