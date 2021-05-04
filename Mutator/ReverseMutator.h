#ifndef TABLEOFLIFE_REVERSEMATER_H
#define TABLEOFLIFE_REVERSEMATER_H

#include "IMutator.h"

//реверсит все биты
template <std::size_t N>
class ReverseMutator : public IMutator<N> {
public:
    explicit ReverseMutator(float probability, std::size_t variants)
            : probability(probability), variants(variants){};
    ~ReverseMutator() = default;
    Genome<N>* Mutate(Genome<N>*) override;

private:
    float probability;
    std::size_t variants;
};

template <std::size_t N>
Genome<N>* ReverseMutator<N>::Mutate(Genome<N>* genome) {
    if (genome == nullptr) {
        return nullptr;
    }

    std::size_t value = genome->GetGenes().size();
    Genome<N>* mutant = new Genome<N>(value);

    // TODO: вынести в оператор копирования
    for (int i = 0; i < value; ++i) {
        mutant->SetGenes(genome->GetGenes());
    }

    auto check = rand();
    float rands = float(check) / (float)RAND_MAX;
    if (rands < probability) {
        // TODO: тут возможно проще сразу все гены изменить
        for (int i = 0; i < value; ++i) {
            mutant->SetGene(i, (mutant->GetGene(i) xor rand()) % variants);
        }
    }

    return mutant;
}
#endif  // TABLEOFLIFE_REVERSEMATER_H
