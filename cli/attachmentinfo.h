#ifndef CLI_ATTACHMENT_INFO
#define CLI_ATTACHMENT_INFO

#include <tagparser/diagnostics.h>

namespace TagParser {
class AbstractContainer;
class AbstractAttachment;
} // namespace TagParser

namespace Cli {

enum class AttachmentAction { Add, Update, Remove };

class AttachmentInfo {
public:
    constexpr AttachmentInfo();
    void parseDenotation(const char *denotation);
    void apply(TagParser::AbstractContainer *container, TagParser::Diagnostics &diag);
    void apply(TagParser::AbstractAttachment *attachment, TagParser::Diagnostics &diag);
    void reset();
    bool next(TagParser::AbstractContainer *container, TagParser::Diagnostics &diag);

    AttachmentAction action;
    std::uint64_t id;
    bool hasId;
    const char *path;
    const char *name;
    const char *mime;
    const char *desc;
};

constexpr AttachmentInfo::AttachmentInfo()
    : action(AttachmentAction::Add)
    , id(0)
    , hasId(false)
    , path(nullptr)
    , name(nullptr)
    , mime(nullptr)
    , desc(nullptr)
{
}

} // namespace Cli

#endif // CLI_ATTACHMENT_INFO
