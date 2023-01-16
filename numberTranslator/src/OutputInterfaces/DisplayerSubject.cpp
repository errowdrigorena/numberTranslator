/*
 * DisplayerSubject.cpp
 *
 *  Created on: Jan 16, 2023
 *      Author: iban
 */

#include <OutputInterfaces/DisplayerSubject.hpp>
#include <OutputInterfaces/IObserver.hpp>

#include <algorithm>

namespace output_interfaces
{

void Displayer_subject::attach(std::shared_ptr<IObserver> observer)
{
	observers_.insert(observer);
}

void Displayer_subject::notify()
{
    for (auto& observer : observers_)
    {
    	observer->update(text_);
    }
}

void Displayer_subject::shareText(const std::string& text)
{
	text_ = text;
	notify();
}

}
