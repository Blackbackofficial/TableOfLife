#ifndef TABLEOFLIFE_SELECTOR_H
#define TABLEOFLIFE_SELECTOR_H

#include "ISelector.h"
#include "../Genome/Genome.h"

template< std::size_t N >
class Selector: public ISelector<N> {
public:
  explicit Selector() = default;;
  Genome<N>* Select(std::vector<Genome<N>*>*) override;
};

template <std::size_t N>
Genome<N>* Selector<N>::Select(std::vector<Genome<N> *>*) {
  return nullptr;
}

#endif // TABLEOFLIFE_SELECTOR_H
