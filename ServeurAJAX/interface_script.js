$(document).ready(function() {
    var max_fields      = 10; //maximum input boxes allowed
    var wrapper         = $('.display-section').find('.search_input_wrapper'); //Fields wrapper// changer selecteur
    var add_button      = $('.display-section').find('.search_input_wrapper').find('.add_search_input'); //Add button ID
    
    var x = 0; //initlal text box count
   
    $(add_button).click(function(e){ //on add input button click
        e.preventDefault();
        if(x < max_fields){ //max input box allowed
            x++; //text box increment
            $(wrapper).append('<div><input type="text" name="SearchInput" class="autocomplete_button" /><a href="#" class="remove_field">Supprimer</a></div>'); 
            
            $(wrapper).find('input[type=text]:last').autocomplete({
                source: "Completion.php",
            });	
            //add input box
        }
    });
	
    //Action du bouton bouton suppression
    $(wrapper).on("click",".remove_field", function(e){ 
        e.preventDefault(); $(this).parent('div').remove(); x--;
    })
    
    $("input[name^='SearchInput']").autocomplete({
		source: "Completion.php",
		minLength :2 ,
	});	
    
});




