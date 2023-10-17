#ifndef TWITTER_DATA_H
#define TWITTER_DATA_H

#include <iostream>
#include <string>

class TwitterData
{
public:
	std::string getUserName() const;   // we do want to return a copy of the string, not the pointer
	std::string getActualName() const; // we do want to return a copy of the string, not the pointer
	std::string getEmail() const;	   // we do want to return a copy of the string, not the pointer
	std::string getCategory() const;   // we do want to return a copy of the string, not the pointer
	int getNumTweets() const;		   // we do want to return a copy of the integer, not the pointer

	void setUserName(const std::string &newUserName);
	void setActualName(const std::string &newActualName);
	void setEmail(const std::string &newEmail);
	void setCategory(const std::string &newCategory);
	void setNumTweets(const int &newNumTweets);

	std::string print() const;

private:
	std::string mpUserName, mpActualName,
		mpEmail, mpCategory;
	int mpNumTweets;
};

inline std::string TwitterData::getUserName() const
{
	return this->mpUserName;
}

inline std::string TwitterData::getActualName() const
{
	return this->mpActualName;
}

inline std::string TwitterData::getEmail() const
{
	return this->mpEmail;
}

inline std::string TwitterData::getCategory() const
{
	return this->mpCategory;
}

inline int TwitterData::getNumTweets() const
{
	return this->mpNumTweets;
}

inline void TwitterData::setUserName(const std::string &newUserName)
{
	this->mpUserName = newUserName;
}

inline void TwitterData::setActualName(const std::string &newActualName)
{
	this->mpActualName = newActualName;
}

inline void TwitterData::setEmail(const std::string &newEmail)
{
	this->mpEmail = newEmail;
}

inline void TwitterData::setCategory(const std::string &newCategory)
{
	this->mpCategory = newCategory;
}

inline void TwitterData::setNumTweets(const int &newNumTweets)
{
	this->mpNumTweets = newNumTweets;
}

inline std::string TwitterData::print() const
{
	return mpUserName + "," + mpActualName + "," + mpEmail + "," + std::to_string(mpNumTweets) + "," + mpCategory;
}

#endif

