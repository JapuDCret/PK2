namespace pk2 {
  class Eminem
  {
  private:
    const char* text;
    Eminem* next;
  public:
    Eminem(const char* t, Eminem* e = nullptr) : text{ t }, next{ e } {};
    const char* get_text() const { return text;  }
    Eminem* get_next() const { return next; }
    void set_next(Eminem* n) { next=n; }  };
}