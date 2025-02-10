#include <zephyr/kernel.h>
#include <zephyr/devicetree.h>

#define SLEEP_TIME_MS   100U

// Node identifier by /aliases node.
// DT_ALIAS(alias) = DT_N_ALIAS_ ## alias
#define NODE_PROPS_ALIAS_BY_LABEL       DT_ALIAS(alias_by_label)        // direct from dt
#define NODE_PROPS_ALIAS_BY_PATH        DT_ALIAS(alias_by_path)
#define NODE_PROPS_ALIAS_BY_STRING      DT_ALIAS(alias_as_string)

// Node identifier by /chosen node.
// DT_CHOSEN(chosen) = DT_N_CHOSEN_ ## chosen
#define NODE_PROPS_CHOSEN_BY_LABEL      DT_CHOSEN(chosen_by_label)
#define NODE_PROPS_CHOSEN_BY_PATH       DT_CHOSEN(chosen_by_path)
#define NODE_PROPS_CHOSEN_AS_STRING     DT_CHOSEN(chosen_as_string)


typedef struct {
        bool boolean_exists;
        int32_t int_value;
        char *string_value;
        int32_t enum_int_value;
        char *enum_string_value;
} values_t;

// the properties here should be named such as those dashes in .dts is
// replaced by _ !!
// Remember, the property name is appended to the token!
const values_t values = {
        .boolean_exists    = DT_PROP(NODE_PROPS_ALIAS_BY_LABEL, existent_boolean),
        .int_value         = DT_PROP(NODE_PROPS_ALIAS_BY_PATH, int),
        .string_value      = DT_PROP(NODE_PROPS_ALIAS_BY_STRING, string),
        .enum_int_value    = DT_PROP(NODE_PROPS_CHOSEN_BY_LABEL, enum_int),
        .enum_string_value = DT_PROP(NODE_PROPS_CHOSEN_BY_PATH, enum_string),
};

int main(void)
{
        printk("Message from freestanding project.\n");
        printk("DT values = {\n");
        printk("  .boolean_exists     = %d\n", values.boolean_exists);    // = 1
        printk("  .int_value          = %d\n", values.int_value);         // = 1
        printk("  .string_value       = %s\n", values.string_value);      // = "foo bar baz"
        printk("  .enum_int_value     = %d\n", values.enum_int_value);    // = 200
        printk("  .enum_string_value  = %s\n", values.enum_string_value); // = "whatever"
        printk("}\n");
        
        printk(
            "The index within enum-int of the selected value %d is %d.\n",
            values.enum_int_value,
            DT_ENUM_IDX(NODE_PROPS_CHOSEN_AS_STRING, enum_int));
            
        printk(
            "The index within 'enum_string' of the selected value '%s' is %d.\n",
            values.enum_string_value,
            DT_ENUM_IDX(NODE_PROPS_CHOSEN_AS_STRING, enum_string));

        while (1) {
                k_msleep(SLEEP_TIME_MS); // Sleep for 100 ms.
        }
        
        return 0;
}

