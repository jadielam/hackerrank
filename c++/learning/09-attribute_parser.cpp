#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include "../utils/string.cpp"
#include "../utils/debug.cpp"
using namespace std;

struct Tag {
    string name;
    map<string, Tag> child_tags;
    map<string, string> attributes;
};

struct Query {
    vector<string> path;
    string attribute;
};

Query parse_query(string line) {
    size_t index = line.find('~');
    string attribute = line.substr(index + 1, string::npos);
    string path_str = line.substr(0, index);
    vector<string> path = utils::string::split_string(path_str, ".");
    Query query {path, attribute};
    return query;
}

Tag parse_tag_line(string line) {
    map<string, Tag> child_tags = map<string, Tag>();
    map<string, string> attributes = map<string, string>();
    
    //1. Find name
    size_t a = line.find(' ');
    size_t b = line.find('>');
    size_t c = min(a, b);
    string name = line.substr(1, c - 1);

    //2. Find attribute pairs
    string pairs_str = line.substr(min(a + 1, line.length() - 1), string::npos);
    vector<string> pairs = vector<string>();
    
    size_t pos = 0;
    while ((pos = pairs_str.find("=")) != string::npos) {
        string key = pairs_str.substr(0, pos);
        utils::string::trim(key);
        
        size_t a = pairs_str.find("\"");
        size_t b = pairs_str.find("\" ");
        string value = pairs_str.substr(a + 1, b - a - 1);

        attributes.insert(pair<string, string>(key, value));

        pairs_str.erase(0, b + 2);
    }

    Tag tag {name, child_tags, attributes};
    return tag;
}

bool is_closing_tag(string line) {
    if (line.substr(0, 2) == "</") {
        return true;
    }
    return false;
}

bool is_opening_tag(string line) {
    return line[1] != '/';
}

string read_next_line() {
    string line;
    getline(cin, line);
    return line;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N;
    int Q;
    cin >> N;
    cin >> Q;  
    cin.ignore(256, '\n');
    
    stack<Tag> s = stack<Tag>();
    map<string, Tag> root_tags = map<string, Tag>();
    for (int i = 0; i < N; ++i) {
        string next_line = read_next_line();
        
        if (is_closing_tag(next_line)) {
            s.pop();
        }
        else if (is_opening_tag(next_line)) {
            Tag tag = parse_tag_line(next_line);
            
            if (!s.empty()) {
                s.top().child_tags.insert(pair<string, Tag&>(tag.name, tag));
            }
            else {
                root_tags.insert(pair<string, Tag&>(tag.name, tag));
            }
            s.push(tag);
        }
    }

    for (int i = 0; i < Q; ++i) {
        string next_line = read_next_line();
        Query query = parse_query(next_line);
        map<string, Tag> * current_map = &root_tags;
        Tag * current_tag;
        
        bool found = true;
        for (string tag_name : query.path) {
            map<string, Tag>::iterator i = current_map->find(tag_name);
            if (i != current_map->end()) {
                Tag inner_tag = i->second;
                current_tag = &inner_tag;
                current_map = &(inner_tag.child_tags);
            }
            else found = false;
        }
        if (found) {
            current_tag->attributes.find(query.attribute);
            map<string, string>::iterator i = current_tag->attributes.find(query.attribute);
            if (i != current_tag->attributes.end()) cout << i->second << endl;
            else found = false;
        }
        if (!found) cout << "Not Found!" << endl;
    }

    return 0;
}