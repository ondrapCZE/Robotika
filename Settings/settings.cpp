#include "settings.hpp"

#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/property_tree/info_parser.hpp>

using namespace std;

Settings::Settings(const string& filename, bool create) :
    filename_(filename) {
    reset(create);
}

Settings::~Settings() {
}

void Settings::reset(bool create) {
    if (isInit()) {
        if (create) {
            boost::filesystem::path p(filename_);
            if (!boost::filesystem::exists(p)) {
                boost::filesystem::create_directories(p.parent_path());
                ofstream f(p.string(), ios::app);
                if (f.is_open()) {
                    f.close();
                }
            }
        }

        try{
            boost::property_tree::info_parser::read_info(filename_, settings_);
        }
        catch (boost::property_tree::info_parser_error error){
            printf("Cannot read input file\n");
        }
    }
}

void Settings::reset(const string& filename, bool create) {
    filename_ = filename;
    reset(create);
}

bool Settings::save() {
    if (isInit()) {
        boost::property_tree::info_parser::write_info(filename_, settings_);
        return true;
    }

    return false;            
}

boost::property_tree::ptree& Settings::getTree() {
    return settings_;
}

bool Settings::isInit() const {
    return !filename_.empty();
}

bool Settings::contains(const string& key) const {
    try  {
        settings_.get_child(key);
        return true;
    } catch (boost::property_tree::ptree_bad_path ex) {
        return false;
    }
}

