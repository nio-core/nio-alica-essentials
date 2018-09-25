#pragma once

#include <engine/constraintmodul/ISolver.h>

#include <memory>
#include <vector>

namespace alica {

class AlicaEngine;
class ProblemDescriptor;
class Variable;
class SolverVariable;

namespace reasoner {

class DummySolver : public alica::ISolver {
public:
    DummySolver(AlicaEngine* ae);
    virtual ~DummySolver();

    bool existsSolution(const VariableGrp& vars, std::vector<std::shared_ptr<ProblemDescriptor>>& calls);
    bool getSolution(const VariableGrp& vars, std::vector<std::shared_ptr<ProblemDescriptor>>& calls,
                             std::vector<void*>& results);
    virtual std::shared_ptr<SolverVariable> createVariable(long representingVariableId);
};
} /* namespace reasoner */
} /* namespace alica */