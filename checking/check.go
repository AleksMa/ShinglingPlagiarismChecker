package checking

import (
	"github.com/AleksMa/StealLovingYou/models"
)

func Check(first, second models.HashSet) int8 {
	equalCount := 0
	if len(first) > len(second) {
		first, second = second, first
	}
	for hash := range first {
		if _, ok := second[hash]; ok {
			equalCount++
		}
	}
	//fmt.Println("EQUAL COUNT: ", equalCount)
	return int8(equalCount * 100 / (len(first) + len(second) - equalCount))
}

func CheckObjects(first, second *models.HashObject) int8 {
	return Check(*first.Set, *second.Set)
}
