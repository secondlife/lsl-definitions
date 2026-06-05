class LLScriptFinalDamageEvent : public LLScriptEvent
{
public:
    LLScriptFinalDamageEvent(S32 line, S32 col, LLScriptIdentifier *num_detected)
        : LLScriptEvent(line, col, LSTT_FINAL_DAMAGE)
        , mNumDetected(num_detected)
    {
    }

    ~LLScriptFinalDamageEvent()
    {
    }

    void recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype,
                 BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count,
                 LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize,
                 LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata);
    S32 getSize();

    LLScriptIdentifier *mNumDetected;
};

class LLScriptGameControlEvent : public LLScriptEvent
{
public:
    LLScriptGameControlEvent(S32 line, S32 col, LLScriptIdentifier *id, LLScriptIdentifier *button_levels, LLScriptIdentifier *axes)
        : LLScriptEvent(line, col, LSTT_GAME_CONTROL)
        , mId(id)
        , mButtonLevels(button_levels)
        , mAxes(axes)
    {
    }

    ~LLScriptGameControlEvent()
    {
    }

    void recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype,
                 BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count,
                 LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize,
                 LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata);
    S32 getSize();

    LLScriptIdentifier *mId;
    LLScriptIdentifier *mButtonLevels;
    LLScriptIdentifier *mAxes;
};

class LLScriptOnDamageEvent : public LLScriptEvent
{
public:
    LLScriptOnDamageEvent(S32 line, S32 col, LLScriptIdentifier *num_detected)
        : LLScriptEvent(line, col, LSTT_ON_DAMAGE)
        , mNumDetected(num_detected)
    {
    }

    ~LLScriptOnDamageEvent()
    {
    }

    void recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype,
                 BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count,
                 LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize,
                 LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata);
    S32 getSize();

    LLScriptIdentifier *mNumDetected;
};

class LLScriptOnDeathEvent : public LLScriptEvent
{
public:
    LLScriptOnDeathEvent(S32 line, S32 col)
        : LLScriptEvent(line, col, LSTT_ON_DEATH)

    {
    }

    ~LLScriptOnDeathEvent()
    {
    }

    void recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype,
                 BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count,
                 LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize,
                 LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata);
    S32 getSize();


};

class LLScriptStateEntryEvent : public LLScriptEvent
{
public:
    LLScriptStateEntryEvent(S32 line, S32 col)
        : LLScriptEvent(line, col, LSTT_STATE_ENTRY)

    {
    }

    ~LLScriptStateEntryEvent()
    {
    }

    void recurse(LLFILE *fp, S32 tabs, S32 tabsize, LSCRIPTCompilePass pass, LSCRIPTPruneType ptype,
                 BOOL &prunearg, LLScriptScope *scope, LSCRIPTType &type, LSCRIPTType basetype, U64 &count,
                 LLScriptByteCodeChunk *chunk, LLScriptByteCodeChunk *heap, S32 stacksize,
                 LLScriptScopeEntry *entry, S32 entrycount, LLScriptLibData **ldata);
    S32 getSize();


};

