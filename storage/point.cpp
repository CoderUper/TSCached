//
// Created by 金祝光 on 2021/4/20.
//

#include "point.h"
#include <cassert>
#include <iostream>
namespace TSCached{

/*
 *******Field类的实现*******
 */
Field::Field():timestamp(time(nullptr)) {
}

Field::Field(const Field &field)
:timestamp(field.timestamp),fields(field.fields)
{

}

Field::Field(Field &&field)
 noexcept :timestamp(field.timestamp),fields(std::move(field.fields))
{

}

bool Field::IsEmpty() const {
    return fields.empty();
}

void Field::Print() const {
    if (fields.empty())
        return;
    for (const auto &data : fields){
        std::cout<<data.first<<"="<<data.second<<"  ";
    }
    std::cout<<"\n";
}


/*
 * ******* Point 类的实现 ********
 */
Point::Point(std::string &db, std::string &tn, std::map<std::string, std::string> &tags)
:DataBase(db),TableName(tn),Tags(tags)
{

}

Point::Point(const QueryPoints& queryPoints)
:DataBase(queryPoints.DataBase),TableName(queryPoints.TableName),Tags(queryPoints.Tags)
{

}

std::string & Point::GetDBName()  {
    return DataBase;
}
std::string & Point::GetTableName()  {
    return TableName;
}
std::map<std::string, std::string> & Point::GetTags() {
    return Tags;
}

time_t Point::GetStartTime() const {
    if (Fields.empty()){
        return -1;
    }
    return Fields.begin()->timestamp;
}

time_t Point::GetEndTime() const {
    if (Fields.empty()){
        return -1;
    }
    return Fields.back().timestamp;
}

std::string  Point::GetKey() const {
    assert(!this->DataBase.empty());
    assert(!this->TableName.empty());
    assert(!this->Tags.empty());
    std::string key=this->DataBase+"&"+this->TableName;
    for(const auto& kv : this->Tags){
        key +="&" + kv.first + "=" +kv.second;
    }
    return key;
}
void Point::Insert(Field &field) {
    this->Fields.push_back(field);
}
std::vector<Field>& Point::GetFields() {
    return this->Fields;
}



/*
 * ********QueryPoints类的实现
 */
std::string QueryPoints::GetKey() {
    assert(!this->DataBase.empty());
    assert(!this->TableName.empty());
    assert(!this->Tags.empty());
    std::string key=this->DataBase+"&"+this->TableName;
    for(const auto& kv : this->Tags){
        key +="&" + kv.first + "=" +kv.second;
    }
    return key;
}

void QueryPoints::Insert(Field &field) {
    if (field.IsEmpty())
        return;
    fields.push_back(field);
}

void QueryPoints::Print() const {
    std::cout<<"************** "<<DataBase<<" *************"<<std::endl;
    std::cout<<"************** "<<TableName<<" *************"<<std::endl;
    for (const auto &it : Tags){
        std::cout<<it.first<<"="<<it.second<<"  ";
    }
    std::cout<<"\n";
    for (const auto& field : fields){
        field.Print();
    }
}

QueryPoints::QueryPoints(const std::string &db, const std::string &tn,const std::map<std::string, std::string> &tags)
:DataBase(db),TableName(tn),Tags(tags)
{

}

QueryPoints::QueryPoints(Point &point)
:DataBase(point.GetDBName()),TableName(point.GetTableName()),Tags(point.GetTags())
{

}


}
