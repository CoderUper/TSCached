//
// Created by 金祝光 on 2021/4/20.
//

#ifndef TSCACHED_POINT_H
#define TSCACHED_POINT_H

#include <string>
#include <vector>
#include <map>
#include <list>
#include <ctime>

namespace TSCached{

class Field{
public:
    Field();
    Field(Field&& field) noexcept ;  //移动构造函数
    Field(const Field&);
    ~Field() = default;
    bool IsEmpty() const ;
    void Print() const ;

public:
    std::map<std::string,double> fields;
    time_t timestamp;  //時間戳
};

class Point;

class QueryPoints{
public:
    std::string DataBase;
    std::string TableName;
    std::map<std::string,std::string> Tags;
    time_t start_;   //开始时间
    time_t end_;     //结束时间
public:
    QueryPoints(const std::string& db,const std::string& tn,const std::map<std::string,std::string>& tags);
    explicit QueryPoints(Point&);
    std::string GetKey();
    void Insert(Field& field);
    void Print() const ;

private:
    std::list<Field> fields;
};

class Point{
public:
    explicit Point(std::string& db,std::string& tn,std::map<std::string,std::string>& tags);
    explicit Point(const QueryPoints& queryPoints);
    //这里还可以改进下，用移动构造函数。
    [[nodiscard]] std::string GetKey() const;
    //插入數據
    void Insert(Field& field);
    std::vector<Field>& GetFields() ;

    [[nodiscard]] time_t GetStartTime() const ;
    [[nodiscard]] time_t GetEndTime() const ;

    std::string& GetTableName() ;
    std::string& GetDBName() ;
    std::map<std::string,std::string>& GetTags() ;
private:
    std::string DataBase;
    std::string TableName;
    std::map<std::string,std::string> Tags;
    std::vector<Field> Fields;
};



} //namespace TSCached

#endif //TSCACHED_POINT_H
