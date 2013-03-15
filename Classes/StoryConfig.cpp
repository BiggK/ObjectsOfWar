#include "StoryConfig.h"

Story001::Story001()
{
	Page newPage;
	newPage.stringId = 0;
	m_pageList.push_back(newPage);
	newPage.stringId = 1;
	m_pageList.push_back(newPage);
}
Story001::~Story001()
{
	Page newPage;
	newPage.stringId = 0;
	m_pageList.push_back(newPage);
}