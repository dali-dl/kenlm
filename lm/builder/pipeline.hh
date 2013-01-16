#ifndef LM_BUILDER_PIPELINE__
#define LM_BUILDER_PIPELINE__

#include "lm/builder/initial_probabilities.hh"
#include "lm/builder/header_info.hh"
#include "util/stream/config.hh"
#include "util/file_piece.hh"

#include <string>
#include <cstddef>

namespace lm { namespace builder {

struct PipelineConfig {
  std::size_t order;
  std::string vocab_file;
  util::stream::ChainConfig chain;
  util::stream::SortConfig sort;
  InitialProbabilitiesConfig initial_probs;
  util::stream::ChainConfig read_backoffs;
  bool verbose_header;

  const std::string &TempPrefix() const { return sort.temp_prefix; }
  std::size_t TotalMemory() const { return sort.total_memory; }
};

// Takes ownership of text_file.
void Pipeline(const PipelineConfig &config, int text_file, std::ostream &out);

}} // namespaces
#endif // LM_BUILDER_PIPELINE__
