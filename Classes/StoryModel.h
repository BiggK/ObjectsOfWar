#ifndef __STORY_MODEL_H__
#define __STORY_MODEL_H__

#include <vector>

typedef struct
{
	unsigned int stringId;
} Page;

class StoryModel
{
public:
    StoryModel();
	virtual ~StoryModel();
	std::vector<Page> m_pageList;
private:

};

#endif