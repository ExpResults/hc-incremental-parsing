#ifndef __ZUOPAR_UTILS_IO_DATASET_DEPENDENCY_H__
#define __ZUOPAR_UTILS_IO_DATASET_DEPENDENCY_H__

#include <iostream>
#include <vector>
#include "types/dependency.h"
#include "utils/io/instance/dependency.h"
#include "engine/token_alphabet.h"

namespace ZuoPar {
namespace IO {

namespace eg = ZuoPar::Engine;

/**
 * Read dependency dataset. In each instance, one item per line. For each item,
 * there are 4 column representing: form, postag, head, deprel. Instances are
 * separated by newline.
 *
 *  @param[in]  is                The input stream.
 *  @param[out] dataset           The output dataset.
 *  @param[out] forms_alphabet    The alphabet for forms.
 *  @param[out] postags_alphabet  The alphabet for postags.
 *  @param[out] deprels_alphabet  The alphabet for dependency relations.
 *  @param[in]  incremental       If incremental is true, insert the token into
 *                                the alphabet, otherwise not perform insertion.
 */
void read_dependency_dataset(std::istream& is,
    std::vector<Dependency>& dataset,
    eg::TokenAlphabet& forms_alphabet,
    eg::TokenAlphabet& postags_alphabet,
    eg::TokenAlphabet& deprels_alphabet,
    size_t flag = 0xffff);

void read_conllx_dependency_dataset(std::istream& is,
    std::vector<CoNLLXDependency>& dataset,
    eg::TokenAlphabet& forms_alphabet,
    eg::TokenAlphabet& lemmas_alphabet,
    eg::TokenAlphabet& cpostags_alphabet,
    eg::TokenAlphabet& postags_alphabet,
    eg::TokenAlphabet& feat_alphabet,
    eg::TokenAlphabet& deprels_alphabet,
    size_t flag = 0xffff);

void read_raw_dependency_dataset(std::istream& is,
    std::vector<RawDependency>& dataset);

void read_raw_conllx_dependency_dataset(std::istream& is,
    std::vector<RawCoNLLXDependency>& dataset,
    bool dummy_root=true,
    const std::string& root="-ROOT-");

}
}

#endif  //  end for __ZUOPAR_UTILS_IO_DATASET_H__
