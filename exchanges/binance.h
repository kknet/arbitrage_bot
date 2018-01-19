#ifndef BINANCE_H
#define BINANCE_H

#include "../utils/restapi.h"
#include "../utils/unique_json.hpp"
#include "../utils/quote_t.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <array>
#include <cmath>
#include <unordered_map>
#include <ctime>

class Binance {
private:
  std::ofstream& log_file;
  quote_array_t price;


public:
  std::vector<std::string> symbols;
  std::unordered_map<std::string, int> symbol_map;
  static RestApi& query_handle          (std::ofstream& _log_file);
  Binance                               (std::ofstream& _log_file);
  Binance                               (const Binance &) =delete;
  Binance& operator=                    (const Binance &) =delete;
  double get_time                       () const;
  const quote_t& get_quote              (std::string symbol) const;
  const quote_array_t& get_quote_array  () const;
  void update_quotes                    ();

};

#endif
