/*
 * Reification.h
 *
 *  Created on: Jul 17, 2014
 *      Author: psp
 */

#ifndef REIFICATION_H_
#define REIFICATION_H_

#include "Term.h"

namespace AutoDiff
{

	class Reification : public Term
	{
	public:
		Reification(shared_ptr<Term> condition, double min, double max);

		int accept(shared_ptr<ITermVisitor> visitor);

		shared_ptr<Term> aggregateConstants();
		shared_ptr<Term> derivative(shared_ptr<Variable> v);

		const shared_ptr<Term> getNegatedCondition();
		const shared_ptr<Term> getCondition();
		const double getMin();
		const double getMax();

	private:
		shared_ptr<Term> _condition;
		shared_ptr<Term> _negatedCondition;
		double _min;
		double _max;
	};

} /* namespace AutoDiff */

#endif /* REIFICATION_H_ */