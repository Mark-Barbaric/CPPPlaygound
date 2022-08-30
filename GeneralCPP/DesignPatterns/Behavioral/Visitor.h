namespace DesignPatterns::Behavioral{

    // https://coders-corner.net/2018/09/02/the-visitor-pattern-part-1-basics-and-introduction/

    class Visitor;

    class CodecParam{
    public:
        virtual void accept(const Visitor& e) = 0;
        virtual void addVideoTrack();
    };

    class Visitor{
    public:
        virtual void visit(const CodecParam& e) const = 0;
    };

    class CodecVisitor : public Visitor {

    };


    class H264CodeParam : public CodecParam {
    public:
        void accept(const Visitor& v) override {
            v.visit(*this);
        }
    };



}