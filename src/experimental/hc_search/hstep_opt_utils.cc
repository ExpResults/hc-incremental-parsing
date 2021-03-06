#include "app/depparser/opt_utils.h"
#include "experimental/hc_search/hstep_opt_utils.h"
#include "utils/logging.h"

namespace ZuoPar {
namespace Experimental {
namespace HCSearchDependencyParser {
namespace HStep {

namespace dp = ZuoPar::DependencyParser;
namespace po = boost::program_options;

po::options_description build_learn_optparser(const std::string& usage) {
  po::options_description optparser = dp::build_learn_optparser(usage);
  optparser.add_options()
    ("neg-sample", po::value<std::string>()->default_value("best"),
     "The select negative sample strategy:\n"
     " baseline - update both fallout and final.\n"
     " best - update with the best [default].\n"
     " random - update with the random.\n"
     " worst - update with the worst.");

  return optparser;
}

po::options_description build_prepare_optparser(const std::string& usage) {
  po::options_description optparser = dp::build_test_optparser(usage);
  optparser.add_options()
    ("language", po::value<std::string>()->default_value("en"),
     "The language for evaluation:\n"
     " en - English\n"
     " ch - Chinese");

  return optparser;
}

po::options_description build_evaluate_optparser(const std::string& usage) {
  po::options_description optparser = dp::build_test_optparser(usage);
  optparser.add_options()
    ("language", po::value<std::string>()->default_value("en"),
     "The language for evaluation:\n"
     " en - English\n"
     " ch - Chinese");

  return optparser;
}

void show_learn_options(const boost::program_options::variables_map& vm) {
  FrontEnd::show_learn_options(vm);
  _INFO << "[OPT] neg-sample: " << vm["neg-sample"].as<std::string>();
}

void show_prepare_options(const boost::program_options::variables_map& vm) {
  FrontEnd::show_test_options(vm);
  _INFO << "[OPT] language: " << vm["language"].as<std::string>();
}

void show_evaluate_options(const boost::program_options::variables_map& vm) {
  FrontEnd::show_test_options(vm);
  _INFO << "[OPT] language: " << vm["language"].as<std::string>();
}

} //  namespace hstep
} //  namespace hcsearchdependencyparser
} //  namespace experimental
} //  namespace zuopar
