/*
 * DisplayerSubject.hpp
 *
 *  Created on: Jan 16, 2023
 *      Author: iban
 */

#ifndef INCLUDE_OUTPUTINTERFACES_DISPLAYERSUBJECT_HPP_
#define INCLUDE_OUTPUTINTERFACES_DISPLAYERSUBJECT_HPP_

#include <OutputInterfaces/ISubject.hpp>
#include <set>

namespace output_interfaces
{

class Displayer_subject : public ISubject {
public:
  ~Displayer_subject() = default;

  void attach(std::shared_ptr<IObserver> observer) override;

  void shareText(const std::string& text) override;

private:
  void notify() override;

  std::set<std::shared_ptr<IObserver>> observers_;
  std::string text_;
};

}

#endif /* INCLUDE_OUTPUTINTERFACES_DISPLAYERSUBJECT_HPP_ */
