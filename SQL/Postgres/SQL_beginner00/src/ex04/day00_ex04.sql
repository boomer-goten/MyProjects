SELECT format(
        '%s (age:%s,
        gender: ''%s'',
        address: ''%s'' )',
        name,
        age,
        gender,
        address
    ) AS person_information
FROM person
ORDER BY person_information