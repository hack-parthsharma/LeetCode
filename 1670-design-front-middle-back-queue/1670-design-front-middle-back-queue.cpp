class FrontMiddleBackQueue {
public:
  FrontMiddleBackQueue() {}
 
  void pushFront(int val) {
    q_.push_front(val); 
    updateMit(even() ? -1 : 0);
  }
 
  void pushMiddle(int val) {    
    if (q_.empty())
      q_.push_back(val);
    else
      q_.insert(even() ? next(mit_) : mit_, val);
    updateMit(even() ? -1 : 1);
  }
 
  void pushBack(int val) {    
    q_.push_back(val); 
    updateMit(even() ? 0 : 1);
  }
 
  int popFront() {     
    if (q_.empty()) return -1;
    int val = q_.front();
    q_.pop_front();
    updateMit(even() ? 0 : 1);
    return val;
  }
 
  int popMiddle() {    
    if (q_.empty()) return -1;
    int val = *mit_;
    mit_ = q_.erase(mit_);
    updateMit(even() ? -1 : 0);
    return val;
  }
 
  int popBack() {    
    if (q_.empty()) return -1;
    int val = q_.back();
    q_.pop_back();
    updateMit(even() ? -1 : 0);
    return val;
  }
private:  
  void updateMit(int delta) {
    if (q_.size() <= 1) {      
      mit_ = begin(q_);
    } else {
      if (delta > 0) ++mit_;
      if (delta < 0) --mit_;
    }    
  }
  
  bool even() const { return q_.size() % 2 == 0; }
  
  list<int> q_;
  list<int>::iterator mit_;
};