#include "ReligionMapper.h"
#include "ReligionMapping.h"
#include "Log.h"
#include "ParserHelpers.h"

mappers::ReligionMapper::ReligionMapper()
{
	LOG(LogLevel::Info) << "Parsing religion mappings.";
	registerKeys();
	parseFile("configurables/religion_map.txt");
	clearRegisteredKeywords();
}

mappers::ReligionMapper::ReligionMapper(std::istream& theStream)
{
	registerKeys();
	parseStream(theStream);
	clearRegisteredKeywords();
}

void mappers::ReligionMapper::registerKeys()
{
	registerKeyword("link", [this](const std::string& unused, std::istream& theStream)
		{
			const ReligionMapping theMapping(theStream);
			for (const auto& eu4Religion : theMapping.getEU4Religions())
			{
				eu4ToVic2ReligionMap.insert(make_pair(eu4Religion, theMapping.getVic2Religion()));
			}
		});
	registerRegex("[a-zA-Z0-9\\_.:]+", commonItems::ignoreItem);
}

std::optional<std::string> mappers::ReligionMapper::getVic2Religion(const std::string& eu4Religion) const
{
	const auto& mapping = eu4ToVic2ReligionMap.find(eu4Religion);
	if (mapping != eu4ToVic2ReligionMap.end()) return mapping->second;
	return std::nullopt;
}